/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, M = 512;
int mn[M], a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	vector <int> ans;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < M; i++)
		mn[i] = INT_MAX;
	mn[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M; j++) {
			int x = j ^ a[i];
			if (mn[x] < a[i]) {
				mn[j] = min(mn[j], a[i]);
			}
		}
	}
	for (int j = 0; j < M; j++) {
		if (mn[j] != INT_MAX) {
			ans.push_back(j);
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
}