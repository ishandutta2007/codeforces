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
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		if(n&1)
		{
			int t=n>>1;
			int g=(m-1)+(m-1)/t;
			printf("%lld\n",g%n+1);
		}
		else printf("%lld\n",(m-1)%n+1);
	}
	return 0;
}