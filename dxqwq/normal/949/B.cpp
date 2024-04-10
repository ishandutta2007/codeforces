#include<bits/stdc++.h>
#define int long double
using namespace std;
inline long double read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	int n=read();
	signed T=read();
	while(T--)
	{
		int x=read();
		long long qwq=2*n-x;
		int lb=(long double)(qwq&(-qwq));
		printf("%lld\n",(long long)(((2*lb-2)*n+x+lb)/(2*lb)));
	}
	return 0;
}