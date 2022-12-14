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

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 102;

int a[N], dp[N][N][N][2];

signed main()
{
	IO_OP;
	
	int n;
	cin >> n;
	int odd = (n + 1) / 2, even = n / 2;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		if(a[i]){
			if(a[i] & 1) odd--;
			else even--;
		}
	}
	memset(dp, 0x3f, sizeof dp);
	if(a[1]) {
		dp[1][0][0][a[1]&1] = 0;
	} else {
		dp[1][1][0][1] = 0;
		dp[1][0][1][0] = 0;
	}
 	for(int i=2;i<=n;i++) {
		for(int j=0;j<=odd;j++)  {
			for(int k=0;k<=even;k++) {
				for(int l=0;l<2;l++) {
					if(a[i]) {
						if((a[i]&1) == l) {
							for(int r=0;r<2;r++)
								dp[i][j][k][l] = min(dp[i][j][k][l], dp[i-1][j][k][r] + ((a[i]&1) ^ r));
						}
					} else {
						if(l == 1) {
							if(j == 0) continue;
							for(int r=0;r<2;r++)
								dp[i][j][k][l] = min(dp[i][j][k][l], dp[i-1][j-1][k][r] + (l ^ r));
						} else {
							if(k == 0) continue;
							for(int r=0;r<2;r++)
								dp[i][j][k][l] = min(dp[i][j][k][l], dp[i-1][j][k-1][r] + (l ^ r));
						}
					}
				}
			}
		}
	}
	cout << min(dp[n][odd][even][0], dp[n][odd][even][1]) << endl;
}