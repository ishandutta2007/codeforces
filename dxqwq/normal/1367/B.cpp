#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),x=0,y=0;
		for(int i=0; i<n; i++) if((read()-i)&1) if(i&1) x++; else y++;
		if(x!=y) puts("-1"); else printf("%d\n",x);
	}
	return 0;
}