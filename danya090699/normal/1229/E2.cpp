#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
const ll one=1;
const int mod=1e9+7;
map <pair <ll, ll>, int> dp[8];
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
void sum(int &x, int add)
{
    x+=add;
    if(x>=mod) x-=mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, rev=po(100, mod-2);
    cin>>n;
    int sm[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) cin>>sm[a][b];
    dp[0][{1, 0}]=1;
    for(int a=0; a<n; a++)
    {
        int pr[1<<n];
        vector <int> sp;
        for(int mask=0; mask<(1<<n); mask++)
        {
            pr[mask]=1;
            for(int i=0; i<n; i++)
            {
                if(mask&(1<<i)) pr[mask]=(1ll*pr[mask]*sm[a][i])%mod;
                else pr[mask]=(1ll*pr[mask]*(100-sm[a][i]))%mod;
                pr[mask]=(1ll*pr[mask]*rev)%mod;
            }
            if(__builtin_popcount(mask)==a) sp.push_back(mask);
        }
        for(auto it=dp[a].begin(); it!=dp[a].end(); it++)
        {
            pair <ll, ll> cur = (*it).first, add[n], va[1<<n];

            int val=(*it).second;
            for(int b=0; b<sp.size(); b++)
            {
                int mask=sp[b];
                if( (mask<64 and cur.first&(one<<mask)) or
                   (mask>=64 and cur.second&(one<<(mask-64))) )
                {
                    for(int i=0; i<n; i++)
                    {
                        if((mask&(1<<i))==0)
                        {
                            int nmask=mask+(1<<i);
                            if(nmask<64) add[i].first|=(one<<nmask);
                            else add[i].second|=(one<<(nmask-64));
                        }
                    }
                }
            }
            for(int to=0; to<(1<<n); to++)
            {
                sum(dp[a+1][va[to]], (1ll*val*pr[to])%mod);
                for(int i=n-1; i>=0 and (to&(1<<i))==0; i--)
                {
                    va[to+(1<<i)].first=va[to].first|add[i].first;
                    va[to+(1<<i)].second=va[to].second|add[i].second;
                }
            }
        }
    }
    auto it=dp[n].end();
    it--;
    cout<<(*it).second;
}