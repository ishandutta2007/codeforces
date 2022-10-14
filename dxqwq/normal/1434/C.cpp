#include<bits/stdc++.h>
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
long long f(int a,int b,int c,int d,int ll)
{
    return -ll*(ll+1)/2ll*b*d+a*(ll+1);
}
signed main()
{
    int n=read();
    for(int i=1; i<=n; i++) 
    {
        int a=read(),b=read(),c=read(),d=read();
        if(a>b*c) 
        {
            puts("-1");
            continue;
        }
        int t=((a-1)/b)/d;//first t time works
        printf("%lld\n",f(a,b,c,d,t));
    }
    return 0;
}