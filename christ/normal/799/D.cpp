#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using ll = long long;
#define all(x) (x).begin(),(x).end()
const int MN = 1e5+2, BASE = 131, MOD = 1e9+9, MOD2 = 696969697, INV2 = 159611381,LOG = __lg(MN) + 2, INV = 526717562;
int a[MN];
map<int,int> dp[35][35]; //dp[prefix][answer][more needed]
int solve (int x, int y, int h, int w, int n) {
	if (h >= x && w >= y) return 0;
	int ret = 1e9;
	dp[0][0] = {{(h +  x - 1) / h,(w + y - 1) / w}};
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = dp[i-1][j];
			if (j) for (auto &au : dp[i-1][j-1]) { //{more needed h, more needed w}
				int nh = (au.first + a[i] - 1) / a[i], nw = (au.second + a[i] - 1) / a[i];
				if (!dp[i][j].count(nh)) dp[i][j][nh] = au.second;
				else dp[i][j][nh] = min(dp[i][j][nh],au.second);
				if (!dp[i][j].count(au.first)) dp[i][j][au.first] = nw;
				else dp[i][j][au.first] = min(dp[i][j][au.first],nw);
			}
			if (dp[i][j].count(1) && dp[i][j][1] == 1) ret = min(ret,j);
		}
	} 
	return ret;
}
int main () { //answer is at most 34
	int x,y,h,w,n;
	scanf ("%d %d %d %d %d",&x,&y,&h,&w,&n);
	for (int i = 1; i <= n; i++) scanf ("%d",a+i);
	sort(a+1,a+1+n,greater<int>());
	n = min(n,34); int ret = min(solve(x,y,h,w,n),solve(y,x,h,w,n));
	printf ("%d\n",ret>1e8?-1:ret);
    return 0;
}