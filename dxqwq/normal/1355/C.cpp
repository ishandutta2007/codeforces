#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main()
{
	long long a=read(),b=read(),c=read(),d=read();
	long long ans=0;
	for(long long i=a; i<=b; i++)
	{
		long long x=max(b,c+1-i)+i-c;
		long long y=min(c,d+1-i)+i-c;
		ans+=((x+y)*max(y-x+1,0LL))>>1;
		ans+=min(c-min(c,d+1-i),c-b+1)*(d-c+1);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
1 2 3 4
5 6
>=7
*/