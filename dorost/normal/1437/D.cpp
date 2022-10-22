/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 200004;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	deque <int> v;
	for (int i = 1; i < n; i++) {
		int x = i;
		i++;
		while (i < n && a[i] > a[i - 1])
			i++;
		i--;
		v.push_back(i - x + 1);
	}
	int lst = 1, ans = 0;
	while (v.size()) {
		int num = 0;
		for (int i = 0; i < lst && v.size(); i++) {
			num += v[0];
			v.pop_front();
		}
		lst = (num);
		ans++;
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}