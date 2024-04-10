// Problem: O. April Fools' Problem (hard)
// Contest: Codeforces - Helvetic Coding Contest 2017 online mirror (teams allowed, unrated)
// URL: https://codeforces.com/problemset/problem/802/O
// Memory Limit: 256 MB
// Time Limit: 10000 ms
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
int a[500003],b[500003];
signed main()
{
	int n=read(),k=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i) b[i]=read();
	int l=-2e9,r=2e9,lst=1e18;
	while(l<=r)
	{
		int mid=(l+r)>>1,ans=0,k0=0;
		priority_queue<pair<int,int>> q;
		for(int i=1; i<=n; ++i)
		{
			q.push(make_pair(mid-a[i],1));
			auto it=q.top();
			q.pop();
			if(b[i]<it.first)
				ans-=it.first-b[i],it.first=b[i],
				k0+=it.second,it.second=0;
			q.push(it);
		}
		ans+=mid*k0;
		if(k0==k) printf("%lld\n",ans),exit(0);
		else if(k0<k) l=mid+1;
		else lst=ans,r=mid-1;
	}
	printf("%lld\n",lst);
	return 0;
}