#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int dp[35][2][2][2][2];

int solve(int li, int ri) {
	memset(dp, 0, sizeof dp);
	dp[31][1][1][1][1] = 1;
	for(int i=30;i>=0;i--) {
		int l = li >> i & 1, r = ri >> i & 1;
		for(int ael=0;ael<2;ael++)
			for(int aer=0;aer<2;aer++)
				for(int bel=0;bel<2;bel++)
					for(int ber=0;ber<2;ber++)
						for(int a=0;a<2;a++) 
							for(int b=0;b<2;b++) {
								if(a && b) continue;
								if(ael && a < l) continue;
								if(aer && a > r) continue;
								if(bel && b < l) continue;
								if(ber && b > r) continue;
								dp[i][ael && a == l][aer && a == r][bel && b == l][ber && b == r] += dp[i+1][ael][aer][bel][ber];
							}
	}
	int ans=0;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)
					ans += dp[0][i][j][k][l];
	return ans;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int li, ri;
		cin >> li >> ri;
		cout << solve(li, ri) << endl;
	}

}