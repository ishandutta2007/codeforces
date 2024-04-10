#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define ll long long
#define MOD 1000000007
#define MN 100000
#define MM 1000000
int P[3]={2333333,9875321,10000007};
int h[3][MM+5],ls[MM+5],a[MM+5],s[MM+5],p[3][MN+5],js[MM+5];
ll f[MM+5];
int main()
{
	int n,m,i,j,k,g,ans=1,c=1;
	n=read();m=read();
	for(i=0;i<3;++i)for(j=p[i][0]=1;j<=n;++j)p[i][j]=(ll)p[i][j-1]*P[i]%MOD;
	for(i=1;i<=n;++i)
	{
		g=read();
		for(j=0;j<g;++j)++s[a[j]=read()];
		for(j=0;j<g;++j)if(ls[a[j]]!=i)
		{
			for(k=0;k<3;++k)h[k][a[j]]=((ll)h[k][a[j]]*p[k][i-ls[a[j]]]+s[a[j]])%MOD;
			ls[a[j]]=i;
		}
		for(j=0;j<g;++j)--s[a[j]];
	}
	for(i=1;i<=m;++i)for(k=0;k<3;++k)f[i]=f[i]*23333+(ll)h[k][i]*p[k][n-ls[i]]%MOD;
	for(js[0]=i=1;i<=m;++i)js[i]=(ll)js[i-1]*i%MOD;
	sort(f+1,f+m+1);
	for(i=1;i<=m;++i)if(f[i]!=f[i-1])ans=(ll)ans*js[i-c]%MOD,c=i;
	printf("%d",(ll)ans*js[m+1-c]%MOD);
}