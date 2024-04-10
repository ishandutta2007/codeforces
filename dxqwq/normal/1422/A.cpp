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
signed main()
{
	for(int T=read(); T--;)
	{
		long long x=read(),y=read(),z=read();
		printf("%lld\n",x+y+z-1);
	 } 
	return 0;
}