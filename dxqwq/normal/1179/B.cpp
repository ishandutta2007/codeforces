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
	int n=read(),m=read();
	for(int l=1,r=n; l<r; ++l,--r) for(int j=1; j<=m; j++) printf("%lld %lld\n%lld %lld\n",l,j,r,m+1-j);
	if(n&1)
	{
		int x=(n+1)/2;
		for(int l=1,r=m; l<=r; ++l,--r) 
		{
			printf("%lld %lld\n",x,l);
			if(l!=r) printf("%lld %lld\n",x,r);
		}
	}
	return 0;
	
}