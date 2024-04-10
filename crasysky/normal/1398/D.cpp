#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=202; int x[N],y[N],z[N],dp[N][N][N];
int main(){
	int a,b,c; scanf("%d%d%d",&a,&b,&c);
	rep(i,1,a) scanf("%d",&x[i]); sort(x+1,x+1+a),reverse(x+1,x+1+a);
	rep(i,1,b) scanf("%d",&y[i]); sort(y+1,y+1+b),reverse(y+1,y+1+b);
	rep(i,1,c) scanf("%d",&z[i]); sort(z+1,z+1+c),reverse(z+1,z+1+c);
	int ans=0;
	rep(i,0,a)
		rep(j,0,b)
			rep(k,0,c){
				if (i&&j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+x[i]*y[j]);
				if (i&&k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+x[i]*z[k]);
				if (j&&k) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+y[j]*z[k]);
				ans=max(ans,dp[i][j][k]);
			}
	cout<<ans<<endl;
	return 0;
}