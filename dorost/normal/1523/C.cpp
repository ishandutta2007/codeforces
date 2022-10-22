/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];
vector <int> v[N];

void printv(vector <int> v) {
	for (int i = 0; i < (int)v.size() - 1; i++) {
		cout << v[i] << '.';
	}
	cout << v[v.size() - 1] << '\n';
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		v[i].clear();
		cin >> a[i];
	}
	set <vector <int>> st;
	v[0] = {1};
	printv(v[0]);
	st.insert(v[0]);
	vector <int> temp;
	for (int i = 1; i < n; i++) {
		v[i] = v[i - 1];
		if (a[i] == 1) {
			v[i].push_back(1);
		} else {
			for (int j = 0; j < i; j++) {
				if (v[j].back() == a[i] - 1) {
					temp = v[j];
					temp.back()++;
					if (!st.count(temp) && temp > v[i - 1]) {
						v[i] = v[j];
						v[i].back()++;
					}
				}
			}
		}
		st.insert(v[i]);
		printv(v[i]);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}