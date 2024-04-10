#include<bits/stdc++.h>
#define N 200000
#define mod 998244353
int T,n,m,k,q,x[N+5],y[N+5];
bool visx[N+5],visy[N+5];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&m,&k,&q);
        for(int i=1;i<=q;++i)
            scanf("%d %d",x+i,y+i);
        int ans=1,cntx=0,cnty=0;
        for(int i=q;i && cntx!=n && cnty!=m;--i)
        {
            if(visx[x[i]] && visy[y[i]]) continue;
            if(!visx[x[i]]) visx[x[i]]=1,++cntx;
            if(!visy[y[i]]) visy[y[i]]=1,++cnty;
            ans=1ll*ans*k%mod;
        }
        for(int i=1;i<=q;++i)
            visx[x[i]]=visy[y[i]]=0;
        printf("%d\n",ans);
    }
    return 0;
}