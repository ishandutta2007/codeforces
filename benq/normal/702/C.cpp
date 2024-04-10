#include <bits/stdc++.h>
using namespace std;

// returns the first index in the array that is >= value, or arr.size() if no such index exists
int firstAtLeast(const vector<int>& arr, int value) {
	int lo = 0, hi = arr.size();
	while (lo < hi) {
		int mid = (lo+hi)/2;
		if (arr[mid] >= value) hi = mid;
		else lo = mid+1;
	}
	return lo;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> cities, towers;
    for (int i = 0; i < n; i++) {
        int city; cin >> city; cities.push_back(city);
    }
    for (int i = 0; i < m; i++) {
        int tower; cin >> tower; towers.push_back(tower);
    }

    int minR = 0;
    for (int i = 0; i < n; i++) {
        int towerRight = firstAtLeast(towers, cities[i]);
        int towerLeft = towerRight - 1;

        int minRForThisCity = 2e9;
        if (towerRight < m) {
            assert(towers[towerRight] >= cities[i]);
            minRForThisCity = min(minRForThisCity, towers[towerRight] - cities[i]);
        }
        if (towerLeft >= 0) {
            assert(towers[towerLeft] <= cities[i]);
            minRForThisCity = min(minRForThisCity, cities[i] - towers[towerLeft]);
        }

        minR = max(minR, minRForThisCity);
    }

    cout << minR << endl;
}