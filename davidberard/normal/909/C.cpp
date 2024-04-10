#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef complex<ld> pt;

int N;
vector<string> gd;
ll dp[5005][5005];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	cin >> N;
	vector<string> ss(N);
	for(int i=0;i<N;++i)
		cin >> ss[i];

	vector<pii> next(N);
	for(int i=N-1;i>=0;--i) {
		if(ss[i] == "s")
			next[i] = pii(i+1, 0);
		else
			next[i] = pii(next[i+1].first, 1+next[i+1].second);
	}

	for(int i=0;i<N;++i) {
		dp[N-1][i] = i+1;
		dp[N][i] = 1;
	}

	for(int i=N-2;i>=0;--i) {
		int tnxt = next[i].first;
		int toff = next[i].second;
		dp[i][0] = dp[next[i].first][next[i].second];
		//cerr << "... " << tnxt << ", " << toff << "::" << dp[tnxt][toff] << endl;
		//cerr << "dp[" << i << "][" << 0 << "] = " << dp[i][0] << endl;
		ll sm = dp[i][0];
		for(int l=1;l+toff<N && l <= i+2;++l) {
			sm += dp[tnxt][toff+l];
			sm %= MOD;
			dp[i][l] = sm;
			//cerr << "dp[" << i << "][" << l << "] = " << dp[i][l] << endl;
		}
	}
	cout << dp[0][0] << endl;
	

	
	return 0;
}