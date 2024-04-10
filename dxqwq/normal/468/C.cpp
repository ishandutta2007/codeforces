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
	int x=read(),y=4500000000000000000ll%x*2%x*9%x;
	printf("%lld %lld\n",x-y,x-y+999999999999999999ll);
	return 0;
}