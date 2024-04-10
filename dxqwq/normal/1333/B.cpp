#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[114514],b[114514];
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),Min;	
		for(int i=1; i<=n; i++) a[i]=read();
		for(int i=1; i<=n; i++) b[i]=read();
		bool x=0,y=0,flag=0;
		for(int i=1;i<=n;i++)
		{
			if((!y&&a[i]>b[i]) || (!x&&a[i]<b[i]) ) {flag=true; break; }
			if(a[i]==1) x=1;
			if(a[i]==-1) y=1;
		}
		if(!flag) puts("yes"); else puts("no");
	}
	return 0;
}