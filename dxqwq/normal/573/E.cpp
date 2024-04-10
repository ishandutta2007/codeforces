// Problem: CF573E Bear and Bowling
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF573E
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
ll a[100003];
ll f[100003];
signed main()
{
	memset(f,0xc0,sizeof(f));
	f[0]=0;
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i)
		for(int j=i; j>=1; --j)
			(f[j]<f[j-1]+a[i]*j)&&(f[j]=f[j-1]+a[i]*j);
	ll ans=0;
	for(int i=1; i<=n; ++i) (ans<f[i])&&(ans=f[i]);
	printf("%lld\n",ans);
	return 0;
}