#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
char s[3030],t[3030];
int n,m,dp[3030][3030],ans;
int main()
{
	scanf("%s %s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;++i)if(s[1]==t[i]||i>m)dp[1][i]=2;
	for(int i=1;i<n;++i)
		for(int j=1;j<=n;++j)
			if(dp[i][j])
			{
				if(j+i<=n&&(j+i>m||s[i+1]==t[j+i]))add(dp[i+1][j],dp[i][j]);
				if(j&&(j-1>m||s[i+1]==t[j-1]))add(dp[i+1][j-1],dp[i][j]);
			}
	// for(int i=1;i<=n;++i)
	// {
	// 	for(int j=1;j<=n;++j)printf("%d ",dp[i][j]);printf("\n");
	// }
	for(int i=m;i<=n;++i)add(ans,dp[i][1]);
	printf("%d",ans);
	return 0;
}