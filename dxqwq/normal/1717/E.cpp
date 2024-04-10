// Problem: E. Madoka and The Best University
// Contest: Codeforces - Codeforces Round #818 (Div. 2)
// URL: https://codeforces.com/contest/1717/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
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
const int p=1e9+7;
int phi[1000003],prime[1000003];
bool vis[1000003];
int cnt;
signed main()
{
	//f[j]:sum=j,coprime
	int n=read(),ans=0;
    for(int i=2; i<=n; ++i)
    {
        if(!vis[i]) prime[++cnt]=i,phi[i]=i-1;
        for(int j=1; j<=cnt&&i*prime[j]<=n; ++j)
        if(i%prime[j]) 
        vis[i*prime[j]]=1,
        phi[i*prime[j]]=phi[i]*(prime[j]-1);
        else{vis[i*prime[j]]=1,phi[i*prime[j]]=phi[i]*prime[j];break;}
    }
	// for(int i=1; i<=10; ++i) printf("%lld ",phi[i]);
	// puts("");
	for(int x=1; x*2<n; ++x)
	{
		int g=n/x,z=x/__gcd(n,x);
		for(int j=2; x*j<n; ++j)
			ans=(ans+z*(n-x*j)%p*phi[j])%p;
	}
	printf("%lld\n",ans);
	return 0;
}