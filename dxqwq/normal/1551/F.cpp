// Problem: F. Equidistant Vertices
// Contest: Codeforces - Codeforces Round #734 (Div. 3)
// URL: https://codeforces.com/contest/1551/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
vector<int> e[1003];
int fac[1003],ifac[1003];
int C(int n,int m)
{
	return fac[n]*ifac[n-m]%p*ifac[m]%p;
}
int n,K;
int cnt[1003][1003];
void dfs(int x,int fa,int dep,int id)
{
#undef local
#ifdef local
	printf("%lld ",x);
#endif
	++cnt[id][dep];
	for(int i:e[x]) if(i!=fa) dfs(i,x,dep+1,id);
	return ;
}
int f[1003];
signed main()
{
	fac[0]=ifac[0]=1;
	for(int i=1; i<=1000; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int T=read();T--;)
	{
		n=read(),K=read();
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<n; ++i)
		{
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		if(K==2)
		{
			printf("%lld\n",n*(n-1)/2);
			continue;
		}
		int ans=0;
		for(int i=1; i<=n; ++i)
		{
			int c=0;
			for(int j=1; j<=n; ++j) for(int k=1; k<=n; ++k)
				cnt[j][k]=0;
			for(int j:e[i]) dfs(j,i,1,++c);
			
			for(int j=1; j<=n; ++j)//dep
			{
				for(int k=1; k<=n; ++k) f[k]=0;
				f[0]=1;
				for(int k=1; k<=c; ++k)//
				{
					for(int l=n; l>=1; --l)
						f[l]=(f[l]+f[l-1]*cnt[k][j])%p; 
				}
				ans=(ans+f[K])%p;
			}
#ifdef local
			printf("RESULT %lld\n",ans);
			puts("---------");
#endif 
		}
		printf("%lld\n",ans);
	}
	return 0;
}