#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;


void solve() {

	int n;
	cin >> n;

	n *= 2;

	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];

	vector<int> sz;
	int cur = -1, len = 0;

	for (int i = 0; i < n; ++i) {
		if (v[i] > cur) {
			if (len) sz.pb(len);
			len = 1;
			cur = v[i];
		}
		else len++;
	}

	sz.pb(len);

	vector<bool> dp(n+1, false);
	dp[0] = true;

	for (int i = 0; i < sz.size(); ++i) {
		int a = sz[i];
		for (int j = n; j >= a; j--) {
			if (dp[j-a]) dp[j] = true;
		}
	}

	if (dp[n/2]) cout << "YES\n";
	else cout << "NO\n";

}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) solve();

}