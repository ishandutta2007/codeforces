//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
#define int long long
int a[200003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n; ++i) a[i]=0;
		for(int i=1; i<=m; ++i) ++a[read()];
		int l=1,r=m<<1,ans=m<<1;
		while(l<=r)
		{
			int mid=(l+r)>>1,sum=0;
			for(int i=1; i<=n; ++i) 
			{
				if(mid<=a[i]) sum+=mid;
				else sum+=a[i]+((mid-a[i])>>1);
			}
			if(sum>=m) ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}