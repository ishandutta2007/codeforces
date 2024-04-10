#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000000
#define MOD 1000000007
int a[MN+5],c[MN+5],cn,v[MN+5],*C[MN+5];
int pw(int x,int y)
{
	int r=1;
	for(;y;y>>=1,x=1LL*x*x%MOD)if(y&1)r=1LL*r*x%MOD;
	return r;
}
int main()
{
	int n,k,y,i,j,x,ans=0;long long l;
	scanf("%d%I64d%d",&n,&l,&k);y=l%n;l/=n;
	for(i=1;i<=n;++i)a[i]=c[i]=read();
	sort(c+1,c+n+1);cn=unique(c+1,c+n+1)-c-1;
	for(i=1;i<=n;++i)a[i]=lower_bound(c+1,c+cn+1,a[i])-c;
	for(i=1;i<=n;++i)++v[a[i]];
	for(i=0;i<=k;++i)C[i]=new int[cn+5],memset(C[i],0,sizeof(int)*(cn+5));
	for(i=0;i<=cn;++i)C[0][i]=1;
	for(i=1;i<=k;++i)for(j=1;j<=cn;++j)C[i][j]=(C[i][j-1]+1LL*C[i-1][j]*v[j])%MOD;
	for(i=1;i<=k;++i)
	{
		ans=(ans+max(l-i+1,0LL)%MOD*C[i][cn])%MOD;
		if(l+1>=i)for(j=1;j<=y;++j)ans=(ans+C[i-1][a[j]])%MOD;
	}
	printf("%d",ans);
}