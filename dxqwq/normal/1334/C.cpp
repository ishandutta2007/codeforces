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
long long a[1000003],b[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),pos=-1;long long Min=1000000000003;
		for(int i=1; i<=n; i++) a[i]=readll(),b[i]=readll();
		for(int i=1; i<=n; i++) 
		{
			b[i]=min(a[i%n+1],b[i]);if(b[i]<Min) Min=b[i],pos=i;
		}
		long long ans=0;
		for(int i=1; i<=n; i++) ans+=a[i]-b[i];
		ans+=b[pos];
		printf("%lld\n",ans);
	}
	return 0;
}