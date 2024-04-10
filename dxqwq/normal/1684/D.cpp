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
int a[1000003];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; ++i) a[i]=read()-n+(i-1);
		int ans=n*(n+1)/2;
		sort(a+1,a+n+1);
		for(int i=1; i<=n-k; ++i) ans+=a[i];
		printf("%lld\n",ans-k*(k+1)/2);
	}
	return 0;
}