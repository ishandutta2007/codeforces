// Problem: E2. Chiori and Doll Picking (hard version)
// Contest: Codeforces - Codeforces Round #635 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1336/E2
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
int d[63],sd[63];
void insert(int x,int m)
{
    for(int i=m-1,tmp=1ll<<(m-1); i>=0; --i,tmp>>=1) 
        if(x&tmp)
        {
            if(d[i]) x^=d[i]; 
            else 
            {
                d[i]=x;
                return ;
            }
        }
    return ;
}
bool s[63][63];
int ans[63],cnt[63],fac[63],ifac[63];
int C(int n,int m)
{
	if(m<0||m>n) return 0;
	return fac[n]*ifac[m]%p*ifac[n-m]%p;
}
int S=0,P=1,Q=1;
void dfs(int cur,int dep)
{
	if(dep==S) {++cnt[__builtin_popcountll(cur)];return ;}
	dfs(cur,dep+1),dfs(cur^sd[dep],dep+1);
	return ;
}
void sfd(int cur,int dep)
{
	if(dep<S) {++cnt[__builtin_popcountll(cur)];return ;}
	sfd(cur,dep-1),sfd(cur^sd[dep],dep-1);
	return ;
}
signed main()
{
	int n=read(),m=read();
	fac[0]=ifac[0]=1;
	for(int i=1; i<=60; ++i) fac[i]=fac[i-1]*i%p,ifac[i]=qp(fac[i],p-2);
	for(int i=1; i<=n; ++i) insert(read(),m);
	for(int i=m-1; i>=0; --i) if(d[i])
	{
		for(int j=m-1; j>=0; --j)
			s[S][j]=((1ll<<j)&d[i])>0;
		sd[S++]=d[i];
	}
	
	if(S<=26) 
	{
		dfs(0,0);
		for(int i=1; i<=n-S; ++i) P=(P<<1)%p;
		for(int i=0; i<=m; ++i) ans[i]=cnt[i];
	}
	else
	{
			// for(int j=0; j<S; ++j,puts(""))
				// for(int k=0; k<m; ++k) putchar(48+s[j][k]);
			// puts("");
		for(int i=0; i<S; ++i)
		{
			for(int j=i; j<m&&!s[i][i]; ++j) if(s[i][j])
				for(int k=0; k<S; ++k) swap(s[k][j],s[k][i]);
			assert(s[i][i]);
			for(int j=0; j<S; ++j) if(i!=j&&s[j][i])
				for(int k=i; k<m; ++k) s[j][k]^=s[i][k];
			// for(int j=0; j<S; ++j,puts(""))
				// for(int k=0; k<m; ++k) putchar(48+s[j][k]);
			// puts("");
		}
		for(int i=S; i<m; ++i) s[i][i]=1;
		for(int i=S; i<m; ++i)
			for(int j=0; j<S; ++j)
				s[i][j]=s[j][i];
		for(int i=S; i<m; ++i)
			for(int k=0; k<m; ++k) if(s[i][k])
				sd[i]+=1ll<<k;
		sfd(0,m-1);
		for(int i=1; i<=n; ++i) P=(P<<1)%p;
		for(int i=1; i<=m; ++i) Q=(Q<<1)%p;
		P=P*qp(Q,p-2)%p;	
		for(int i=0; i<=m; ++i)
			for(int j=0; j<=m; ++j)
				for(int k=0; k<=m; ++k)
					ans[i]=(ans[i]+((k&1)?998244352ll:1ll)*cnt[j]%p*C(j,k)%p*C(m-j,i-k))%p;
	}
	for(int i=0; i<=m; ++i) printf("%lld ",ans[i]*P%p);
	return 0;
}