#include<bits/stdc++.h>
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
int a[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int k;
		for(int i=1; i<=n; i++)
		{
			k=read(),++a[k];
		}
		int x=0,y=0;
		for(int i=1; i<=n; i++)
		{
			if(a[i]) ++x;
			y=max(y,a[i]);
		}
		if(x<y) printf("%d\n",min(x,y-1));else if(x==y) printf("%d\n",x-1); else printf("%d\n",min(x-1,y));
		for(int i=1; i<=n; i++) a[i]=0;
	}
	return 0;
}