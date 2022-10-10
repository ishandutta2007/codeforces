#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Passenger {
	int floor;
	int timeArival;
};

bool cmpPassenger (Passenger p1, Passenger p2) {
	return (p1.floor == p2.floor)
		? p1.timeArival < p2.timeArival
		: p1.floor > p2.floor
	;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int i, k;
	int n, s;
	cin >> n >> s;
	vector <Passenger> arr(n + 1);

	for (i = 0; i < n; ++i) {
		cin >> arr[i].floor >> arr[i].timeArival;
	}

	arr[n].floor = s;
	arr[n].timeArival = 0;

	sort(arr.begin(), arr.end(), cmpPassenger);

	int result = 0;

	for (i = 1; i <= n; ++i) {
		result += arr[i - 1].floor - arr[i].floor;
		if (result < arr[i].timeArival) result = arr[i].timeArival;
	}

	result += arr[n].floor;

	cout << result;

	return 0;
}