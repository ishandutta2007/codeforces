#include<cstdio>
int n,m,dp[5010][5010],w[5010][5010];
char ch;
void read(int &x)
{
	for (ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for (x=0;ch<='9'&&ch>='0';ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
}
int max(int x,int y)
{return x>y?x:y;}
int main()
{
	int l,r;
	read(n);
	for (int i=1;i<=n;i++) read(w[i][i]),dp[i][i]=w[i][i];
	for (int i=n-1;i;i--)
		for (int j=i+1;j<=n;j++)
			dp[i][j]=max(max(dp[i+1][j],dp[i][j-1]),w[i][j]=w[i+1][j]^w[i][j-1]);
	read(m);
	while (m--) read(l),read(r),printf("%d\n",dp[l][r]);
	return 0;
}