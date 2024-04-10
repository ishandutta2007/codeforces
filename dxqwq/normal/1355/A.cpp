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
inline long long calc(long long x)
{
	long long Mx=0,Mn=9;
	while(x)
	{
		Mx=max(Mx,x%10);
		Mn=min(Mn,x%10);
		x/=10;
	}
	return Mx*Mn;
}

int main()
{
	int T=read();
	while(T--)
	{
		long long n=readll(),m=readll();
		--m;
		while(m-- && calc(n)) n+=calc(n);
		printf("%lld\n",n);
	}
	return 0;
}