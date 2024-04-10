//Shit round
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
		int n=read();
		if(n==1)
		{
			puts("9");
			continue;
		}
		printf("9");
		for(int i=2,x=8; i<=n; i++,x++)
		{
			if(x==10) x=0;
			printf("%lld",x);
		}
		puts("");
	}
	return 0;
}