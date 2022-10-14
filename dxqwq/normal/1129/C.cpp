// Problem: C. Morse Code
// Contest: Codeforces - Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1)
// URL: https://codeforces.com/problemset/problem/1129/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const ll p0=1945555039024054273;
struct magic_hash_table
{
	int nxt[5000003];
	ll val[5000003];
	int head[16777216],cnt;
	inline bool insert(ll x)
	{
		int id=x&16777215;
		ll w=x>>24;
		for(int i=head[id]; i; i=nxt[i]) 
			if(val[i]==w) return 0;
		nxt[++cnt]=head[id],val[cnt]=w,head[id]=cnt;
		return 1;
	}
}mp;
int a[3003],f[3003][32];
signed main()
{
	int n=read(),ans=0;
	ll h=0;
	for(int i=1; i<=n; h=0,++i)
	{
		a[i]=read(),f[i+1][1]=1;
		for(int j=i; j>=1; --j)
		{
			memset(f[j],0,sizeof(f[j]));
			for(int k=1; k<16; ++k)
				f[j][(k<<1)+a[j]]=(f[j][(k<<1)+a[j]]+f[j+1][k])%p;
			for(int k=2; k<32; ++k)
				if(k!=0b11010
				 &&k!=0b11100
				 &&k!=0b10111
				 &&k!=0b11111)
				 	f[j][1]=(f[j][1]+f[j][k])%p;
			h=(h*3+a[j]+1)%p0,
			(mp.insert(h))&&(ans=(ans+f[j][1])%p);
		}
		printf("%d\n",ans);
	}
	return 0;
}