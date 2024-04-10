#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int M = 1e9 + 7;

int a[20], b[20], dp[33000][5];

int32_t main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
		cin >> a[i] >> b[i];
	int ans = 0;
	for(int i=1;i<(1<<n);i++) {
		for(int j=0;j<n;j++) {
			if((i>>j)&1) {
				if((i^(1<<j)) == 0) {
					dp[i][b[j]]=1;
					break;
				}
				for(int l=1;l<=3;l++)
					if(l != b[j])
						dp[i][b[j]] += dp[i^(1<<j)][l];
				dp[i][b[j]] %= M;
			}
		}
		int s = 0;
		for(int j=0;j<n;j++)
			if(i>>j&1)
				s += a[j];
		if(s == m) {
			ans += dp[i][1] + dp[i][2] + dp[i][3];
			ans %= M;
		}
	}
	cout << ans << endl;
}