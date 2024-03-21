#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using std::cout;
using std::pair;
using std::vector;
using std::min;
//using namespace std;


int search_points(pair<int, int> point1, pair<int, int> point2, const vector<pair<int, int>>& points) {

	int counter1 = 0, counter2 = 0;

	for (const auto& point : points) {
		int vector_multi = (point.second - point1.second) * (point2.first - point1.first) -
			(point.first - point1.first) * (point2.second - point1.second);

		if (vector_multi > 0) {
			counter1++;
		}
		else if (vector_multi < 0) {
			counter2++;
		}
	}
	return min(counter1, counter2);
}
	pair<pair<int, int>, pair<int, int>> search_min_points(const vector<pair<int, int>>&points) {

		int min_meaning = INT_MAX;
		pair<pair<int, int>, pair<int, int>> optimal_points;
		for (size_t i = 0; i < points.size(); ++i) {
			for (size_t j = i + 1; j < points.size(); ++j) {
				int difference = abs(search_points(points[i], points[j], points));
				if (difference < min_meaning) {
					min_meaning = difference;
					optimal_points = { points[i], points[j] };
				}
			}
		}
		return optimal_points;
	}

	
