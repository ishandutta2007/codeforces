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
	int n=read(),sum=0;
	for(int i=1; i<=n; i++) sum+=read();
	int x=(((sum<<1)/n-n+1)>>1),y=sum-((((x<<1)+n-1)*n)>>1);
	for(int i=1; i<=n; i++) if(i<=y) printf("%lld ",i+x); else printf("%lld ",i+x-1); 
	return 0;
}