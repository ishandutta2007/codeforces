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
    if(n==1&&m==1)
    {
        puts("0");
        return 0;
    }
    if(n==1)
    {
        for(int i=1; i<=m; i++) printf("%lld ",i+1);
        return 0;
    }
    if(m==1)
    {
        for(int i=1; i<=n; i++) printf("%lld\n",i+1);
        return 0;
    }
    for(int i=1; i<=n; i++,puts("")) for(int j=1; j<=m; j++)
    {
        printf("%lld ",i*(n+j));
    }
	return 0;
}