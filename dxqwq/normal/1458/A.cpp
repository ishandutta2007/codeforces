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
int a[1000003],b[1000003];
signed main()
{
	int n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read();
	if(n==1)
	{
		for(int x;m--;) x=read(),printf("%lld ",x+a[1]);
		return 0;
	}
	sort(a+1,a+n+1);
	int t=a[2]-a[1];
	for(int i=3; i<=n; i++) t=__gcd(t,a[i]-a[i-1]);
	for(int x;m--;) x=read(),printf("%lld ",__gcd(x+a[1],t));
	return 0;
}