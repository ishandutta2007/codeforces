#include <iostream>
using namespace std;

int main() {
	int points[3][2];
	
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 2; ++j) {
			cin >> points[i][j];
		}
	}
	
	if (points[0][0] == points[1][0] && points[0][0] == points[2][0]) {
		cout << 1;
		return 0;
	} else if (points[0][1] == points[1][1] && points[0][1] == points[2][1]) {
		cout << 1;
		return 0;
	} else if (points[0][1] == points[1][1]) {
		int x=min(points[0][0], points[1][0]), y=max(points[0][0], points[1][0]);
		if (points[2][0] <= x || y <= points[2][0]) {
			cout << 2;
			return 0;
		}
	} else if (points[0][0] == points[1][0]) {
		int x=min(points[0][1], points[1][1]), y=max(points[0][1], points[1][1]);
		if (points[2][1] <= x || y <= points[2][1]) {
			cout << 2;
			return 0;
		}
	} else if (points[0][1] == points[2][1]) {
		int x=min(points[0][0], points[2][0]), y=max(points[0][0], points[2][0]);
		if (points[1][0] <= x || y <= points[1][0]) {
			cout << 2;
			return 0;
		}
	} else if (points[0][0] == points[2][0]) {
		int x=min(points[0][1], points[2][1]), y=max(points[0][1], points[2][1]);
		if (points[1][1] <= x || y <= points[1][1]) {
			cout << 2;
			return 0;
		}
	} else if (points[1][1] == points[2][1]) {
		int x=min(points[1][0], points[2][0]), y=max(points[2][0], points[1][0]);
		if (points[0][0] <= x || y <= points[0][0]) {
			cout << 2;
			return 0;
		}
	} else if (points[1][0] == points[2][0]) {
		int x=min(points[1][1], points[2][1]), y=max(points[2][1], points[1][1]);
		if (points[0][1] <= x || y <= points[0][1]) {
			cout << 2;
			return 0;
		}
	}
	cout << 3;
}