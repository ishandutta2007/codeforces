#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105;
const int mod=1000000009;
int trans[maxn][4],fail[maxn],queue[maxn],num[maxn],root=1,cnt=1,n,m,dp[1005][maxn][15];
char s[15];
inline int id(char ch)
{
	if(ch=='A')return 0;
	if(ch=='C')return 1;
	if(ch=='G')return 2;
	if(ch=='T')return 3;
}
inline void add(char *s)
{
	int i,p=root;
	for(i=0;s[i]&&trans[p][id(s[i])];i++)p=trans[p][id(s[i])];
	for(;s[i];i++)trans[p][id(s[i])]=++cnt,p=cnt;
	num[p]=max(num[p],(int)strlen(s));
}
inline void getfail()
{
	int head=0,tail=0,i;
	for(i=0;i<4;i++)if(trans[root][i])queue[++tail]=trans[root][i],fail[trans[root][i]]=root;
	else trans[root][i]=root;
	while(head!=tail)
	{
		int x=queue[++head];
		for(i=0;i<4;i++)if(trans[x][i])queue[++tail]=trans[x][i],fail[trans[x][i]]=trans[fail[x]][i],num[trans[x][i]]=max(num[trans[x][i]],num[trans[fail[x]][i]]);
		else trans[x][i]=trans[fail[x]][i];
	}
}
inline void work()
{
	dp[0][1][0]=1;
	for(int i=0;i<n;i++)
		for(int j=1;j<=cnt;j++)
			for(int k=0;k<10;k++)
				for(int c=0;c<4;c++)
					if(num[trans[j][c]]>=k+1)dp[i+1][trans[j][c]][0]=(dp[i+1][trans[j][c]][0]+dp[i][j][k])%mod;
					else if(k+1<=10)dp[i+1][trans[j][c]][k+1]=(dp[i+1][trans[j][c]][k+1]+dp[i][j][k])%mod;
	int ans=0;
	for(int i=1;i<=cnt;i++)ans=(ans+dp[n][i][0])%mod;
	printf("%d",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%s",s);
		add(s);
	}
	getfail();
	work();
	return 0;
}