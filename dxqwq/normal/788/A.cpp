//  zhoukangyang 
#include<bits/stdc++.h>
#define int long long
using namespace std;
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
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	for(int i=n; i>=2; i--) a[i]=abs(a[i]-a[i-1]);
	for(int i=1; i<n; i++) a[i]=a[i+1];
	--n;
	int ans=0;
	for(int i=0,x=0; i<=n;)
	{
		x+=a[++i];
		ans=max(ans,x);
		x-=a[++i];
		if(x<0) x=0;
	}
	for(int i=1,x=0; i<=n;)
	{
		x+=a[++i];
		ans=max(ans,x);
		x-=a[++i];
		if(x<0) x=0;
	}
	printf("%lld\n",ans);
    return 0;
}