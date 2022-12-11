#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
const ll INF=1e18;

int n; ll A,B,C,D;  //check LL
ll w[1000010];
ll dp[2][2][1000010];
inline void chkmin(ll &x,ll y){if (y<x) x=y;}
int main()
{
	n=read(),A=read(),B=read(),C=read(),D=read();
	for (int i=1;i<=n;i++) w[i]=read();
	for (int i=1;i<=n;i++)
		for (int j=0;j<4;j++)
			dp[j&1][j>>1][i]=INF;
	dp[0][0][1]=0;
	for (int i=1;i<n;i++){
		for (int u=0;u<2;u++){
			for (int v=0;v<2;v++){
				if (dp[u][v][i]==INF) continue;
				ll X=0LL+B+A,Y=1LL*w[i]*A+A+A,Z=1LL*w[i]*A+C;
				//1
				if (!v) chkmin(dp[1][0][i+1],dp[u][v][i]+min(X,min(Y,Z))+3LL*D);
				//if (!v) chkmin(dp[1][0][i+1],dp[u][v][i]+Y+3LL*D);
				//if (!v) chkmin(dp[1][0][i+1],dp[u][v][i]+Z+3LL*D);
				//2
				chkmin(dp[0][1][i+1],dp[u][v][i]+min(X,min(Y,Z))+2LL*D);
				//3
				if (u&&!v) chkmin(dp[0][0][i+1],dp[u][v][i]+min(X,Y)+D);
				if (!v) chkmin(dp[0][0][i+1],dp[u][v][i]+Z+D);
			}
		}
	}
	ll ans=INF;
	for (int u=0;u<2;u++)
		for (int v=0;v<2;v++){
			ll X=0LL+B+A,Y=1LL*w[n]*A+A+A,Z=1LL*w[n]*A+C;
			if (u) chkmin(ans,dp[u][v][n]+min(X,Y));
			chkmin(ans,dp[u][v][n]+Z);
		}
	printf("%I64d\n",ans); //I64d
	return 0;
}