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
int a[13],b[100003],n,l=1,r=1,cnt=0;
pair<int,int> x[600003];
int f[100003];
signed main()
{
    for(int i=1; i<=6; i++) a[i]=read();
    n=read();
    for(int i=1; i<=n; i++) b[i]=read();
    sort(b+1,b+n+1);
    for(int i=1; i<=6; i++) for(int j=1; j<=n; j++) x[++cnt]=make_pair(max(b[j]-a[i],1ll),j);
    long long ans=1000000000000ll;
    sort(x+1,x+cnt+1);
    int now=0;
    for(int l=1,r=1; r<=cnt; r++)
    {
        if(f[x[r].second]==0) ++now;
        ++f[x[r].second];
        while(f[x[l].second]>1) --f[x[l].second],++l;
        if(now==n) ans=min(ans,x[r].first-x[l].first);
    }
    printf("%lld\n",ans);
    return 0;
}