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
	int n=read(); 
	for(int i=1; i<=n; i++) 
	{
		for(int j=1; j<n; j++) if((i+1)&1) printf("0 "); else printf("%lld ",1LL<<(i+j));
		if((i+1)&1) printf("0\n"); else printf("%lld\n",1LL<<(i+n));
		fflush(stdout);
	}
	int T=read();
	while(T--)
	{
		int x,nowx=1,nowy=1;
		scanf("%lld",&x);
		while(1)
		{
			printf("%lld %lld\n",nowx,nowy),fflush(stdout);
			if(nowx==n && nowy==n) break;
			int tmp=0;
			if((x>>(nowx+nowy+1))&1LL) ++tmp;
			if(nowx&1) ++tmp;
			if(tmp&1) ++nowx; else ++nowy;
		}
	}
	return 0;
}