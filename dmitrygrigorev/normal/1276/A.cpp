#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int dp[200007][5];
bool take[200007][5];
int wh[200007][5];

const int INF = 1e9;

void solve() {
	string s;
	cin >> s;

	for (int i=0; i <= s.size(); ++i) {
		for (int j=0; j < 5; ++j) {
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	for (int i=0; i < s.size(); ++i) for (int j=0; j < 5; ++j) {
		if (dp[i][j]+1 < dp[i+1][j]) {
			dp[i+1][j] = dp[i][j] + 1;
			take[i+1][j] = false;
			wh[i+1][j] = j;
		}
		int G = 0;
		if (s[i] == 'o') {
			if (j == 2) continue;
			else G = 3;
		}
		else if (s[i] == 'n') {
			if (j == 3) G = 4;
			else G = 0;
		}
		else if (s[i] == 'e') {
			if (j==4) continue;
			G = 0;
		}
		else if (s[i] == 't') {
			G = 1;
		}
		else if (s[i] == 'w') {
			if (j == 1) G = 2;
			else G = 0;
		}
		else G = 0;
		if (dp[i+1][G] > dp[i][j]) {
			dp[i+1][G] = dp[i][j];
			take[i+1][G] = true;
			wh[i+1][G] = j;
		}

	}

	int ans = 1e9, state = -1;
	for (int i=0; i < 5; ++i) {
		if (dp[s.size()][i] < ans) {
			ans = dp[s.size()][i];
			state = i;
		}
	}

	vector<int> dlt;
	for (int i=0; i < s.size(); ++i) {
		if (!take[s.size()-i][state]) dlt.push_back(s.size() - i -1);
		state = wh[s.size() - i][state];
	} 
	cout << dlt.size() <<"\n";
	for (int i=0;i<dlt.size();++i) cout << dlt[i] + 1 << " ";
	cout << "\n";
	
}

int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=0; i < t; ++i) solve();

}