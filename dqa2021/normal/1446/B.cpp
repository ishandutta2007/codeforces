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
#undef G

int n,m;
char s[5010],t[5010];
int dp[5010][5010];
inline void checkmax(int &x,int y){
	if (y>x) x=y;
}
int main()
{
	n=read(),m=read();
	scanf("%s%s",s+1,t+1);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			dp[i][j]=+i+j;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=m;j++){
			if (i<n) checkmax(dp[i+1][j],dp[i][j]);
			if (j<m) checkmax(dp[i][j+1],dp[i][j]);
			if (i<n&&j<m) checkmax(dp[i+1][j+1],dp[i][j]+4*(s[i+1]==t[j+1]));
		}
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			checkmax(ans,dp[i][j]-i-j);
	printf("%d\n",ans);
	return 0;
}