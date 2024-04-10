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
		int n=read(),k=read(),Max=-1000000000;
		for(int i=1; i<=n; i++) a[i]=read(),Max=max(Max,a[i]);
		for(int i=1; i<=n; i++) a[i]=Max-a[i];
		if((k&1)==0)
		{
			int Max=0;
			for(int i=1; i<=n; i++) Max=max(Max,a[i]);
			for(int i=1; i<=n; i++) a[i]=Max-a[i];
		}
		for(int i=1; i<=n; i++) printf("%lld ",a[i]);
		puts("");
	}
	return 0;
}