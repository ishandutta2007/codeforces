// Problem: A. Glory Addicts
// Contest: Codeforces - Codeforces Global Round 22
// URL: https://codeforces.com/contest/1738/problem/0
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		for(int i=1; i<=n; ++i) a[i]=read();
		vector<int> x,y;
		for(int i=1; i<=n; ++i) 
			if(a[i]) x.push_back(read());
			else y.push_back(read());
		sort(x.begin(),x.end()),reverse(x.begin(),x.end());
		sort(y.begin(),y.end()),reverse(y.begin(),y.end());
		if(x.size()==y.size())
		{
			int ans=0;
			for(int i:x) ans+=i;
			for(int i:y) ans+=i;
			printf("%lld\n",ans*2-min(x.back(),y.back()));
		}
		else
		{
			int Z=min(x.size(),y.size());
			int A=x.size(),B=y.size(),ans=0;
			for(int i=0; i<A; ++i)
				if(i<Z) ans+=x[i]*2; else ans+=x[i];
			for(int i=0; i<B; ++i)
				if(i<Z) ans+=y[i]*2; else ans+=y[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}