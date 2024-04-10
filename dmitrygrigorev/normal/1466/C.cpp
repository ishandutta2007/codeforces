#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int INF = 1e9;

int dp[2][2];
int dp2[2][2];

void solve() {
	string s;
	cin >> s;

	if (s.size() == 1) {
		cout << "0\n";
		return;
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			dp[i][j] = (i+j);
		}
	}

	if (s[0] == s[1]) dp[0][0] = INF;

	for (int i = 2; i < s.size(); ++i) {
		for (int last = 0; last < 2; ++last) {
			for (int prev = 0; prev < 2; ++prev) {
				dp2[last][prev] = INF;
				for (int t = 0; t < 2; ++t) {
					if (t == 0 && last == 0 && s[i] == s[i-2]) continue;
					if (prev == 0 && last == 0 && s[i] == s[i-1]) continue;
					dp2[last][prev] = min(dp2[last][prev], dp[prev][t] + last);
				}
			}
		}
		for (int last = 0; last < 2; ++last) {
			for (int prev = 0; prev < 2; ++prev) {
				dp[last][prev] = dp2[last][prev];
			}
		}
	}

	cout << min({dp[0][0], dp[0][1], dp[1][0], dp[1][1]}) << '\n';

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

	for (int i = 0; i <t ; ++i) solve();

}