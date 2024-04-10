#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
const int MN = 203, MK = 1001, MOD = 1e9+7;
mt19937_64 rnd = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());
int a[MN], dp[MN][MN][MK];
void uadd (int &aa, int b) {aa += b; if (aa >= MOD) aa -= MOD;}
int main() {
	int n,K;
	scanf ("%d %d",&n,&K);
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	sort(a+1,a+1+n);
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= K; k++) {
				int diff = a[i] - a[i-1];
				if (j && k >= diff*(j-1)) uadd(dp[i][j][k],dp[i-1][j-1][k-diff*(j-1)]);
				if (k >= diff*j) uadd(dp[i][j][k],dp[i-1][j][k-diff*j]*1LL*(j+1)%MOD);
				if (k >= diff*(j+1)) uadd(dp[i][j][k],dp[i-1][j+1][k-diff*(j+1)]*1LL*(j+1)%MOD);
			}
		}
	}
	int ret = 0;
	for (int i = 0; i <= K; i++) uadd(ret,dp[n][0][i]);
	printf ("%d\n",ret);
    return 0;
}
/*
7 8 9 10
0:
[7] [8] [9] [10]
1:
[7,8] [9] [10]
[7] [8,9] [10]
[7] [8] [9,10]
2:
[7,8,9] [10]
[7] [8,9,10]
[7,9] [8] [10]
[7] [9] [8,10]

 
*/