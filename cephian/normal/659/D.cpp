#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;

int n;
int x[2000],y[2000];

int main() {
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	int ccw = 0;
	int parity = 0;
	for(int i = 1; i < n; ++i) {
		ll ax = x[i] - x[i-1];
		ll ay = y[i] - y[i-1];
		ll bx = x[(i+1)%n] - x[i];
		ll by = y[(i+1)%n] - y[i];
		ll cross = ax*by - ay*bx;
		ccw += cross > 0;
	}
	cout << ccw << "\n";
	return 0;
}