#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int a[100003],n;
long long A,R,M;
long long check(int t)
{
	long long x=0,y=0;
	for(int i=1; i<=n; i++) if(a[i]<t) x+=t-a[i]; else y+=a[i]-t;
	//printf("%d %lld %lld\n",t,x,y);
	return min(A+R,M)*min(x,y)+A*(x-min(x,y))+R*(y-min(x,y));
}
signed main()
{
	n=read(),A=read(),R=read(),M=read();
	int l=0,r=0;
	for(int i=1; i<=n; i++) a[i]=read(),r=max(r,a[i]);
	while(l<r)
	{
		if(r-l==1) break;
		int mid=l+r>>1;
		if(check(mid)>check(mid+1)) l=mid+1; else r=mid;
	}
	printf("%lld",min(check(l),check(l+1)));
	return 0;
}