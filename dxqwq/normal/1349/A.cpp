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
long long a[1000003],b[1000003],ans;
signed main()
{
	int n=read();
	for(int i=1; i<=n; i++) a[i]=read();
	b[n]=a[n],ans=a[n-1]*b[n];
	for(int i=n-1; i>=1; i--) b[i]=__gcd(b[i+1],a[i]);
	for(int i=1; i<n; i++) ans=__gcd(ans,a[i]*b[i+1]);
	ans/=b[1];
	printf("%lld\n",ans);
	return 0;
}