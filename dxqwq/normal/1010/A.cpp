#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
double a[10003],b[10003];
signed main()
{
	int n=read();
	double m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=1; i<=n; i++) b[i]=read();
	for(int i=1; i<=n; i++) if(a[i]==1||b[i]==1) puts("-1"),exit(0);
	double l=1,r=1e9,ans=1e9;
	for(int T=1; T<=200; T++)
	{
		double mid=(l+r)/2.0;
		double now=mid;
		bool f=1;
		for(int i=1; i<n; i++)
		{
			now-=(now+m)/a[i];
			if(now<0.0) 
			{
				f=0;
				break;
			}
			now-=(now+m)/b[i+1];
			if(now<0.0) 
			{
				f=0;
				break;
			}
		}
		now-=(now+m)/a[n];
		if(now<0.0) f=0;
		now-=(now+m)/b[1];
		if(now<0.0) f=0;
		if(f) ans=mid,r=mid; else l=mid;
	}
	printf("%.10lf\n",ans);
	return 0;
}