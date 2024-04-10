/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int ans[N];
bool mark[N];

int ask(int x, int y) {
	cout << "? " << x + 1 << ' ' << y + 1 << endl;
	int k;
	cin >> k;
	return k;
}

void solve() {
	int n;
	cin >> n;
	set <int> st;
	for (int i = 0; i < n; i++) 
		st.insert(i);
	while (st.size() > 1) {
		vector <int> v;
		for (auto x : st) {
			v.push_back(x);
		}
		for (int i = 0; i < (int) v.size() - 1; i += 2) {
			int k = ask(v[i], v[i + 1]);
			int k2 = ask(v[i + 1], v[i]);
			if (k > k2) {
				st.erase(v[i]);
				ans[v[i]] = k;
			}else {
				st.erase(v[i + 1]);
				ans[v[i + 1]] = k2;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		mark[ans[i]] = true;
	}
	int x = -1;
	for (int i = 1; i <= n; i++) 
		if (!mark[i])
			x = i;
	cout << "! ";
	for (int i = 0; i < n; i++) {
		if (ans[i] == 0)
			ans[i] = x;
		cout << ans[i] << ' ';
	}
	cout << endl;
}

int32_t main() {
	solve();
}