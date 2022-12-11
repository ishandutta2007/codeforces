#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
typedef long long ll;
const ll INF=1e18;

int n,bt,w[(1<<18)+10],wtot;
ll dp[(1<<18)+10][19];
void upd(ll &x,ll y)
{
	x=min(x,y);
}
int main()
{
	n=read(); for (bt=0;(1<<bt)<n;bt++);
	bool flg=false;
	for (int i=1,x;i<=n;i++)
	{
		x=read();
		if (x==-1) flg=true;
		else if (flg) w[++wtot]=x;
		else w[++wtot]=0;
	}
	n--;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=bt;j++)
			dp[i][j]=INF;
	dp[0][0]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<=bt;j++)
		{
			if (dp[i][j]==INF) continue;
			upd(dp[i+1][j],dp[i][j]);
			if (i+1>=(1<<j+1)-1) upd(dp[i+1][j+1],dp[i][j]+w[i+1]);
		}
	printf("%I64d\n",dp[n][bt]);  //%I64d!!!
	return 0;
}