/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	vector <int> v, w;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	string s;
	cin >> s;
	int k = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'B')
			v.push_back(a[i]), k++;
		else
			w.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < i + 1) {
			cout << "NO\n";
			return;
		}
	}
	for (int i = 0; i < w.size(); i++) {
		if (w[(int)w.size() - i - 1] > n - i) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}