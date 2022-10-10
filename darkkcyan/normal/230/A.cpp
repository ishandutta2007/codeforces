#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	#define ii pair<int, int>
	int n, s;
	cin >> s >>  n;
	ii a[n];
	for (int i = 0; i < n; ++i) cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) 
		if (s <= a[i].first) return cout << "NO", 0;
		else s += a[i].second;
	cout << "YES";
	return 0;
}