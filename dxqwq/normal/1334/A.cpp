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
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int now=-1,t=-1,tt=-1,f=0;
		while(n--)
		{
			int x=read(),y=read();
			if(x<y || x<t || y<tt) f=1;
			if(x-y>=now) now=x-y,t=x,tt=y; else f=1;
		}
		if(f) printf("NO\n"); else printf("YES\n");
	 } 
	return 0;
}