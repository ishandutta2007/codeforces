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
int p[100003],cnt=0;
bool vis[1000003];
signed main()
{
    for(int i=2; i<=100000; i++)
    {
        if(vis[i]) continue;
        p[++cnt]=i;
        for(int j=2; i*j<=100000; j++) vis[i*j]=1;
    }
    for(int T=read(); T--;)
    {
        int a=read(),b=read(),bb=b;
        if(a%b) printf("%lld\n",a);
        else
        {
            int ans=1;
            for(int j=1; j<=cnt; j++) if(b%p[j]==0)
            {
                int tmp=a;
                while(tmp%bb==0) tmp/=p[j];
                ans=max(ans,tmp);
                while(b%p[j]==0) b/=p[j]; 
            }
            int tmp=a;
            if(b!=1) { while(tmp%bb==0) tmp/=b;
            ans=max(ans,tmp); }
            printf("%lld\n",ans);
        }
    }
    return 0;
}