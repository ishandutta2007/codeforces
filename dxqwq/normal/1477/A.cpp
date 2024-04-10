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
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		for(int i=1; i<=n; i++) a[i]=read();
		sort(a+1,a+n+1);
		int g=a[2]-a[1];
		for(int i=2; i<n; i++) g=__gcd(g,a[i+1]-a[i]);
		if(abs(k-a[1])%g==0) puts("YES");
		else puts("NO");
	}
	return 0;
}