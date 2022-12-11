#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline void add(int &x,int y){(x+=y)>=mod?x-=mod:0;}
inline int pl(int x,int y){return (x+=y)>=mod?x-mod:x;}
inline int kpow(int a,int b)
{
	int s=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)s=1ll*s*a%mod;
	return s;
}
int n,m,ans[60],C[60][60],coef[60][60],po[200020],cnt[60];
long long p[60],a[60],b[60];
int cnta,cntb,pa[60];
void ins(long long x)
{
	for(int i=m-1;~i;--i)
		if(x>>i&1)
		{
			if(!p[i])p[i]=x;
			x^=p[i];
		}
}
void work()
{
	for(int i=0;i<m;++i)
		for(int j=i-1;~j;--j)if((p[i]>>j&1)&&p[j])p[i]^=p[j];
}
void dfs(int pos,long long w)
{
	if(pos==cnta+1)
	{
		++ans[__builtin_popcountll(w)];
		return;
	}
	dfs(pos+1,w);
	dfs(pos+1,w^a[pos]);
}
void dfs1(int pos,long long w)
{
	if(pos==cntb+1)
	{
		++cnt[__builtin_popcountll(w)];
		return;
	}
	dfs1(pos+1,w);
	dfs1(pos+1,w^b[pos]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<=m;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)C[i][j]=pl(C[i-1][j-1],C[i-1][j]);
	}
	for(int i=1;i<=n;++i)
	{
		static long long x;
		scanf("%lld",&x);
		ins(x);
	}
	work();
	for(int i=0;i<m;++i)
		if(p[i])a[++cnta]=p[i],pa[cnta]=i;
		else b[++cntb]=1ll<<i;
	if(cnta<=26)
	{
		dfs(1,0);
		int po=kpow(2,n-cnta)%mod;
		for(int i=0;i<=m;++i)printf("%d ",1ll*ans[i]*po%mod);
	}
	else
	{
		for(int i=1;i<=cntb;++i)
			for(int j=1;j<=cnta;++j)if(a[j]&b[i])b[i]^=1ll<<pa[j];
		dfs1(1,0);
		for(int i=0;i<=m;++i)
			for(int j=0;j<=m;++j)
			{
				for(int k=0;k<=j;++k)
					if(k&1)coef[i][j]=(coef[i][j]+1ll*(mod-C[i][k])*C[m-i][j-k])%mod;
					else coef[i][j]=(coef[i][j]+1ll*C[i][k]*C[m-i][j-k])%mod;
				ans[j]=(ans[j]+1ll*coef[i][j]*cnt[i]%mod)%mod;
			}
		int po=kpow(2,n-m+mod-1);
		for(int i=0;i<=m;++i)printf("%d ",1ll*ans[i]*po%mod);
	}
	return 0;
}