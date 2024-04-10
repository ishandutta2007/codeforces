#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e3; int a[N],dp[N][N];
int aabs(int x){ return x>=0?x:-x; }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		rep(i,1,n)
			rep(j,i,2*n){
				dp[i][j]=dp[i-1][j-1]+aabs(a[i]-j);
				if (j>i) dp[i][j]=min(dp[i][j],dp[i][j-1]);
			}
		cout<<dp[n][2*n]<<endl;
	}
	return 0;
}