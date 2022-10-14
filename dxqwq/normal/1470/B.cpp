//sb nt 
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+(ch&15),ch=getchar();
    return x;
}
int a[1000003],cnt=0,prim[10003];
bool vis[10003];
int p[1000003],q[1000003];
signed main()
{
        for(int i=2; i<=1000; i++) if(!vis[i]) 
        {
            prim[++cnt]=i*i;
            for(int j=2; i*j<=1000; j++) vis[i*j]=1;
        }    
    for(int T=read(); T--;)
    {
        int n=read();
        for(int i=1; i<=n; i++) a[i]=read();
        for(int j=1; j<=n; j++) for(int i=1; i<=cnt; i++) while(a[j]%prim[i]==0) a[j]/=prim[i];
        for(int j=1; j<=n; j++) ++p[a[j]];
        int A=0,B=0;
        unordered_map<int,int> mp;
        for(int i=1; i<=n; i++) 
        {
            int j=a[i];
            if(mp[j]) continue;
            mp[j]=1;
            if(p[j]&1) q[j]+=p[j]; else q[1]+=p[j]; 
        }
        for(int i=1; i<=n; i++) A=max(A,p[a[i]]),B=max(B,q[a[i]]);
        A=max(A,p[1]),B=max(B,q[1]);
        for(int T=read();T--;)
        {
            int x=read();
            if(x==0) printf("%lld\n",A);
            else printf("%lld\n",B);
        }        
        for(int j=1; j<=n; j++) p[a[j]]=q[a[j]]=0;
        p[1]=q[1]=0;
    }
    return 0;
}