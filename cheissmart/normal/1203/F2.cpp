#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int dp[105][120005];

int main()
{
	IO_OP;
	
	int n, r;
	cin >> n >> r;
	vector<pi> pos, neg;
	for(int i=0;i<n;i++) {
		int a, b;
		cin >> a >> b;
		if(b >= 0) pos.EB(a, b);
		else neg.EB(a, b);
	}
	sort(ALL(pos));
	int ans = 0;
	for(int i=0;i<pos.size();i++) {
		if(r >= pos[i].F) {
			r += pos[i].S;
			ans++;
		}
	}
	sort(ALL(neg), [](pi a, pi b) -> bool {
		return a.F + a.S > b.F + b.S;
	});
	for(int i=neg.size()-1;i>=0;i--) {
		for(int j=0;j<60005;j++) {
			dp[i][j] = dp[i+1][j];
			if(j >= neg[i].F && j+neg[i].S >= 0) {
				dp[i][j] = max(dp[i][j], dp[i+1][j+neg[i].S]+1);
			}
		}
	}
	ans += dp[0][r];
	cout << ans << endl;

}