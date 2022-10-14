//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n,m,A0,A1;
int a[103],b[103];
int calc(int x)
{
	int res=0,cnt=0,mx1=0,mx2=0;
	for(int i=1; i<=n; ++i) b[i]=a[i]%x;
	for(int i=1; i<=n; ++i) 
	{
		b[i]=a[i]%x;
		cnt+=(b[i]>=((x+1)>>1));
		if(b[i]>mx1) mx2=mx1,mx1=b[i];
		else if(b[i]>mx2) mx2=b[i];
	}
	res=mx2>>1;
	for(int i=1; i<=n; ++i) res=max(res,min(b[i],x-b[i]-1));
	if(!(cnt&1)) res=x>>1;
	if(res<(x>>1)) return res;
	res=x-(mx1>>1)-1;
	for(int i=1; i<=n; ++i) res=min(res,max(b[i],x-b[i]-1));
	return res;
}
signed main()
{
	n=read(),m=read();
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=2,t,t1;i<=m*2;++i)
		t=min(max(calc(i),i-m-1),i-1),
		(t<0)&&(t=0),(t>m)&&(t=m), 
		t1=min(t-max(i-m,1ll)+1,min(i-1,m)-t),
		A0+=t1,A1+=t-max(i-m,1ll)-t1+1;
	printf("%lld %lld %lld %lld\n",A0,A0,1ll*m*m-(A0<<1)-A1,A1);
	return 0;
}