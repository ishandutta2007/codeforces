#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
#define fi first
#define se second
using namespace std;
const int N=5e3+3; char s[N],t[N]; int dp[N][N];
int main(){
	int n,m,ans=0; scanf("%d%d%s%s",&n,&m,s,t);
	rep(i,1,n)
		rep(j,1,m){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])-1;
			if (s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			ans=max(ans,dp[i][j]=max(dp[i][j],0));
		}
	printf("%d\n",ans);
    return 0;
}