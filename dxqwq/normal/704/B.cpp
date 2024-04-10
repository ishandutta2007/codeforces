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
// txdy!
//zyAC
int nxt[10003];
int a[10003],b[10003],c[10003],d[10003],x[10003];
int calc(int p,int q)
{
    if(x[p]>x[q]) return x[p]-x[q]+c[p]+b[q];
    return x[q]-x[p]+d[p]+a[q];
}
signed main()
{
    int n=read(),s=read(),t=read();
    nxt[s]=t;
    for(int i=1; i<=n; i++) x[i]=read();
    for(int i=1; i<=n; i++) a[i]=read();
    for(int i=1; i<=n; i++) b[i]=read();
    for(int i=1; i<=n; i++) c[i]=read();
    for(int i=1; i<=n; i++) d[i]=read();
    int ans=calc(s,t);
    for(int i=1; i<=n; i++) if(i!=s && i!=t)
    {
        int tmp=s,mn=1000000000000000000ll;
        for(int x=s; nxt[x]; x=nxt[x])
        {
            int now=calc(x,i)+calc(i,nxt[x])-calc(x,nxt[x]);
            if(now<mn) mn=now,tmp=x;
        }
        nxt[i]=nxt[tmp],nxt[tmp]=i,ans+=mn;
    }
    printf("%lld\n",ans);
    return 0;
}