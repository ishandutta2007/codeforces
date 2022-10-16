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

const int INF = 1e9 + 7;

int a[16][10004], n, m;
bool dp[1<<16][16];
vi G[16];

bool ok(int k) {
	for(int i=0;i<n;i++) G[i].clear();
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			bool ok = 1;
			for(int l=0;l<m;l++)
				if(abs(a[i][l] - a[j][l]) < k)
					ok = 0;
			if(ok)  G[i].PB(j), G[j].PB(i);
		}
	}
	for(int i=0;i<n;i++) {
		memset(dp, 0, sizeof dp);
		for(int j=1;j<(1<<n);j++) {
			for(int l=0;l<n;l++) if(j >> l & 1) {
				if(j == (1<<i) && l == i){
					dp[j][l] = 1;
				} else {
					for(int tt:G[l]) {
						if(j >> tt & 1) {
							dp[j][l] |= dp[j^(1<<l)][tt];
						}
					}
				}
			}
		}
		for(int j=0;j<n;j++) {
			bool ok = 1;
			for(int l=0;l<m-1;l++)
				ok &= abs(a[j][l]-a[i][l+1]) >= k;
			if(ok && dp[(1<<n)-1][j]) return true; 
		}
	}
	return false;
}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	int l = 0, r = 1e9;
	while(l <= r) {
		int m = (l + r) / 2;
		if(ok(m)) l = m + 1;
		else r = m - 1;
	}
	cout << r << endl;
}