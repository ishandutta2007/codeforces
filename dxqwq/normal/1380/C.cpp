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
		long long x=readll();
		for(int i=1; i<=n; i++) a[i]=read();
		sort(a+1,a+n+1);
		long long cntx=0,cnty=0;
		int ans=0;
		for(int i=n; i>=1; i--) 
		{
			++cnty,cntx=a[i];
			if(cntx*cnty>=x) ++ans,cntx=cnty=0;
		}
		printf("%d\n",ans);
		
	}
	return 0;
}