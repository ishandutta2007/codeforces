/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 3012, M = 201234;
int dp[2 * N][2 * N];
pair <int, int> a[N];
vector <int> s[M];
int n;
vector <long long> w;

bool is(int l, int r) {
	if (w.back() < (ll)l * (ll)M + (ll)r)
		return false;
	return (*(lower_bound(w.begin(), w.end(), (ll)l * (ll)M + (ll)r))) == (ll)l * (ll)M + (ll)r;
}

void solve() {
	cin >> n;
	vector <int> v;
	w.clear();
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> a[i].F >> a[i].S;
		v.push_back(a[i].F);
		v.push_back(a[i].S);
		w.push_back((ll)a[i].F * (ll)M + (ll)a[i].S);
	}
	for (int i = 0; i < n; i++) {
		s[a[i].F].push_back(i);
	}
	sort(w.begin(), w.end());
	v.push_back(M - 1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = v.size(); i >= 0; i--) {
		for (int j = 0; j <= v.size(); j++) {
			dp[i][j] = -1001001;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = i; j < v.size(); j++) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[i + 1][j] + is(v[i + 1], v[j]);
			for (auto x : s[v[i]]) {
				if (a[x].S >= v[j])
					continue;
				int in = lower_bound(v.begin(), v.end(), a[x].S) - v.begin();
				dp[i][j] = max(dp[i][j], dp[i][in] + dp[in + 1][j] + 1 + is(v[in + 1], v[j]));
			}
		}
	}
	cout << dp[0][v.size() - 1] << ' ';
	for (int i = 0; i < n; i++) {
		s[a[i].F].clear();
	}
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