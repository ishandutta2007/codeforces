#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 5000
#define MOD 1000000007
char s[MN+5];
int g[MN+5][MN+5],a[MN+5][MN+5],A[MN+5][MN+5],b[MN+5][MN+5],B[MN+5][MN+5];
int main()
{
	int n,i,j,ans,x;
	scanf("%s",s+1);n=strlen(s+1);
	memset(g,40,sizeof(g));
	for(i=n;--i;)for(j=n;j>i;--j)g[i][j]=s[i]!=s[j]?0:g[i+1][j+1]+1; 
	memset(b,40,sizeof(b));
	for(i=0;i<=n;++i)A[0][i]=1;
	for(i=1;i<=n;++i)
	{
		for(j=1;i-j+1;++j)if(s[i-j+1]=='1')
		{
			a[i][j]=A[i-j][j-1];
			b[i][j]=B[i-j][j-1]+1;
			if(i-j-j+1>0&&s[i-j-j+1]=='1'&&(g[i-j-j+1][i-j+1]>=j||s[i-j+1+g[i-j-j+1][i-j+1]]=='1'))
			{
				a[i][j]=(a[i][j]+a[i-j][j])%MOD;
				b[i][j]=min(b[i][j],b[i-j][j]+1);
			}
		}
		for(B[i][0]=1e9,j=1;j<=n;++j)A[i][j]=(a[i][j]+A[i][j-1])%MOD,B[i][j]=min(b[i][j],B[i][j-1]);
	}
	printf("%d\n",A[n][n]);
	for(i=1,ans=1e9;i<=n&&i<30;++i)if(b[n][i]<b[0][0])
	{
		for(j=i,x=0;j--;)x=2*x+s[n-j]-'0';
		ans=min(ans,x+b[n][i]);
	}
	if(ans<1e9)return 0*printf("%d",ans);
	for(;i<=n;++i)if(b[n][i]<b[0][0])
	{
		for(j=i,x=0;j--;)x=(2*x+s[n-j]-'0')%MOD;
		printf("%d",(x+b[n][i])%MOD);break;
	}
}