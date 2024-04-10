#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int k, n, m;
    cin>>k>>n>>m;
    int ot0[n][2], ot1[m][2];
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        scanf("%d%d", &ot0[a][0], &ot0[a][1]);
        ot0[a][0]--;
        ma[ot0[a][0]]=0, ma[ot0[a][1]]=0;
    }
    for(int a=0; a<m; a++)
    {
        scanf("%d%d", &ot1[a][0], &ot1[a][1]);
        ot1[a][0]--;
        ma[ot1[a][0]]=0, ma[ot1[a][1]]=0;
    }
    ma[0]=0, ma[k]=0;
    int q=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        (*it).second=q, q++;
    }
    int ma0[q], ma1[q];
    for(int a=0; a<q; a++)
    {
        ma0[a]=-1, ma1[a]=-1;
    }
    for(int a=0; a<n; a++) ma0[ma[ot0[a][1]]]=max(ma0[ma[ot0[a][1]]], ma[ot0[a][0]]);
    for(int a=0; a<m; a++) ma1[ma[ot1[a][1]]]=max(ma1[ma[ot1[a][1]]], ma[ot1[a][0]]);
    int dp0[q], dp1[q],  su0=1, su1=0, yk0=0, yk1=0;
    dp0[0]=1, dp1[0]=0;
    auto it=ma.begin();
    for(int a=1; a<q; a++)
    {
        int d=-(*it).first;
        it++;
        d=po(2, d+(*it).first)-2;
        if(d<0) d+=mod;
        int su02=su0, su12=su1;
        dp0[a]=(1ll*(su0+su1)*d)%mod, dp1[a]=0;
        su0=(su0+dp0[a])%mod;
        while(yk0<=ma1[a])
        {
            su0-=dp0[yk0];
            if(su0<0) su0+=mod;
            dp0[yk0]=0, yk0++;
        }
        while(yk1<=ma0[a])
        {
            su1-=dp1[yk1];
            if(su1<0) su1+=mod;
            dp1[yk1]=0, yk1++;
        }
        if(ma0[a]!=a-1)
        {
            dp1[a-1]=(dp1[a-1]+su02)%mod;
            su1=(su1+su02)%mod;
        }
        if(ma1[a]!=a-1)
        {
            dp0[a-1]=(dp0[a-1]+su12)%mod;
            su0=(su0+su12)%mod;
        }
    }
    cout<<(su0+su1)%mod;
}