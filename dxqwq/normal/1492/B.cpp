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
int a[1000003],mx[1000003],p[1000003];
signed main()
{
	for(int T=read(); T--;)
	{
		int n=read();
		for(int i=1; i<=n; i++) a[i]=read(),p[a[i]]=i;
		for(int i=1; i<=n; i++) mx[i]=max(mx[i-1],a[i]);
		int x=n;
		while(x)
		{
			int pos=p[mx[x]];
			for(int i=pos; i<=x; i++) printf("%d ",a[i]);
			x=pos-1;
		 } 
		 puts("");
	}
    return 0;
}