/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int cnt[N];

void solve() {
	int n, m;
	cin >> n >> m;
	set <pair <int, int> > st;
	for (int i = 0; i < n; i++)
		st.insert({0, i + 1});
	int num = 1;
	while (m--) {
		int x;
		cin >> x;
		st.erase({cnt[x], x});
		cnt[x]++;
		st.insert({cnt[x], x});
		if ((*st.begin()).F >= num) {
			num++;
			cout << '1';
		}else {
			cout << '0';
		}
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}