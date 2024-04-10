#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003]; 
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		int t=read();
		bool f=1;
		for(int i=2; i<=n; i++) if(read()!=t) f=0;
		if(!f) puts("1"); else printf("%d\n",n);
	}
	return 0;
}