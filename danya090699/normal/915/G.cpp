#include <bits/stdc++.h>
using namespace std;
const int sz=2e6+10, mod=1e9+7;
int q[sz], st[sz];
vector <int> de[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        x=(1ll*x*x)%mod;
        y>>=1;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, su=0, an=0;
    cin>>n>>k;
    q[1]=1;
    for(int a=0; a<=k; a++) st[a]=po(a, n);
    for(int a=1; a<=k; a++)
    {
        int add=mod-q[a];
        if(add<0) add+=mod;
        de[a].push_back(a);
        for(int b=a+a; b<=k; b+=a)
        {
            q[b]+=add;
            if(q[b]>=mod) q[b]-=mod;
        }
    }
    for(int a=1; a<=k; a++)
    {
        while(de[a].size())
        {
            int x=de[a].back();
            int qq=a/x;
            su-=(1ll*st[qq-1]*q[x])%mod;
            su+=(1ll*st[qq]*q[x])%mod;
            if(su<0) su+=mod;
            if(su>=mod) su-=mod;
            if(a+x<=k) de[a+x].push_back(x);
            de[a].pop_back();
        }
        an+=(su^a);
        if(an>=mod) an-=mod;
    }
    cout<<an;
}