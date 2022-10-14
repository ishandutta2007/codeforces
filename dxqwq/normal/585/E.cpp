// Problem: E. Present for Vitalik the Philatelist
// Contest: Codeforces - Codeforces Round #325 (Div. 1)
// URL: https://codeforces.com/problemset/problem/585/E
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=1e9+7;
bool vis[10000003];
int prime[10000003],cnt;
int mu[10000003];
int a[10000003];
int p2[500003],g[500003],f[500003];
const int N=10000000;
void init()
{
	mu[1]=1;
    for(int i=2; i<=N; ++i) 
    {
        if(!vis[i]) prime[++cnt]=i,mu[i]=p-1;
        for(int j=1; j<=cnt&&i*prime[j]<=N; ++j) 
        {
            vis[i*prime[j]]=1;
            if(i%prime[j]) (mu[i])&&(mu[i*prime[j]]=p-mu[i]); 
            else break; 
        }
    }
}
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) ++a[read()];
	init();
	for(int i=1; i<=N; ++i)
		for(int j=2; i*j<=N; ++j) a[i]+=a[i*j];
	int ans=0;
	p2[0]=1;
	for(int i=1; i<=n; ++i) p2[i]=(p2[i-1]<<1)%p;
	for(int i=1; i<=n; ++i) g[i]=((g[i-1]<<1)%p+p2[i-1])%p;
	for(int i=1; i<=n; ++i) f[i]=(1ll*n*(p-p2[i]+1)+(g[i]<<1)+p-i)%p;
	for(int i=1; i<=N; ++i)	ans=(ans+1ll*f[a[i]]*mu[i]%p)%p;
	printf("%d\n",ans);
	return 0;
}