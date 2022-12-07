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
int de(int x, int y)
{
    return (1ll*x*po(y, mod-2))%mod;
}
int main()
{
    int n, an=0;
    cin>>n;
    int dp[n+1];
    vector <int> del[n+1];
    for(int a=2; a<=n; a++)
    {
        if(del[a].size()==0)
        {
            for(int b=a; b<=n; b+=a) del[b].push_back(a);
        }
    }
    for(int a=1; a<=n; a++)
    {
        dp[a]=0;
        vector <int> sp;
        for(int b=1; b*b<=a; b++)
        {
            if(a%b==0)
            {
                sp.push_back(b);
                if(a/b!=b) sp.push_back(a/b);
            }
        }
        int wait=de(n/a, n-n/a);
        for(int b=0; b<sp.size(); b++)
        {
            int ne=sp[b], x=a/ne;
            if(x>1)
            {
                int q=0;
                for(int mask=0; mask<(1<<del[x].size()); mask++)
                {
                    int cu=1;
                    for(int i=0; i<del[x].size(); i++) if(mask&(1<<i)) cu*=del[x][i];
                    if(__builtin_popcount(mask)%2==0) q+=(n/ne)/cu;
                    else q-=(n/ne)/cu;
                }
                dp[a]=(dp[a]+1ll*de(q, n-n/a)*(dp[ne]+1+wait))%mod;
            }
        }
        an=(an+1ll*de(1, n)*(dp[a]+1))%mod;
    }
    cout<<an;
}