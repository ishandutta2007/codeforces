#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, mod=998244353;
set <int> sv[sz];
vector <int> sp;
bool us[sz];
int q[25][25], cq=0, su[25];
void dfs(int v)
{
    sp.push_back(v);
    us[v]=1;
    for(auto it=sv[v].begin(); it!=sv[v].end(); it++)
    {
        int ne=(*it);
        if(!us[ne]) dfs(ne);
    }
}

int fact[sz], rev[sz];
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=1ll*re*x%mod;
        y>>=1;
        x=1ll*x*x%mod;
    }
    return re;
}
int C(int n, int k)
{
    return 1ll*(1ll*fact[n]*rev[n-k]%mod)*rev[k]%mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int l[n], r[n];
    for(int a=0; a<n; a++) scanf("%d%d", &l[a], &r[a]);
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].insert(v);
        sv[v].insert(u);
    }

    int qq[n+2];
    vector <pair <pair <int, int>, int> > ev[n+2];

    for(int a=0; a<=n+1; a++) qq[a]=0;

    for(int a=0; a<n; a++)
    {
        if(sv[a].size())
        {
            if(!us[a])
            {
                dfs(a);
                su[cq]=sp.size();
                bool dp[1<<sp.size()];
                for(int mask=0; mask<(1<<sp.size()); mask++)
                {
                    if(mask)
                    {
                        int i=__builtin_ctz(mask), v=sp[i];
                        if(dp[mask-(1<<i)])
                        {
                            dp[mask]=1;
                            for(int j=0; j<sp.size(); j++)
                            {
                                if(mask&(1<<j) and sv[v].find(sp[j])!=sv[v].end()) dp[mask]=0;
                            }
                        }
                        else dp[mask]=0;
                    }
                    else dp[mask]=1;

                    if(dp[mask])
                    {
                        int lg=1, rg=n;
                        for(int i=0; i<sp.size(); i++)
                        {
                            if(mask&(1<<i))
                            {
                                lg=max(lg, l[sp[i]]);
                                rg=min(rg, r[sp[i]]);
                            }
                        }
                        if(lg<=rg)
                        {
                            ev[lg].push_back({{cq, __builtin_popcount(mask)}, 1});
                            ev[rg+1].push_back({{cq, __builtin_popcount(mask)}, -1});
                        }
                    }
                }
                cq++, sp.clear();
            }
        }
        else qq[l[a]]++, qq[r[a]+1]--;
    }

    fact[0]=1, rev[0]=1;
    for(int a=1; a<=n; a++)
    {
        fact[a]=1ll*fact[a-1]*a%mod;
        rev[a]=po(fact[a], mod-2);
    }

    int an=0;
    for(int a=1; a<=n; a++)
    {
        qq[a]+=qq[a-1];

        for(int b=0; b<ev[a].size(); b++)
        {
            q[ev[a][b].first.first][ev[a][b].first.second]+=ev[a][b].second;
        }

        int dp[41], dp2[41];
        for(int b=0; b<=40; b++) dp[b]=0, dp2[b]=0;
        dp[0]=1;
        for(int b=0; b<cq; b++)
        {
            for(int c=0; c<=40; c++)
            {
                if(dp[c])
                {
                    for(int d=0; d<=su[b]; d++)
                    {
                        if(q[b][d]) dp2[c+d]=(dp2[c+d]+1ll*dp[c]*q[b][d])%mod;
                    }
                }
            }
            for(int c=0; c<=40; c++) dp[c]=dp2[c], dp2[c]=0;
        }
        for(int b=0; b<=40; b++)
        {
            if(dp[b] and b<=a and qq[a]>=a-b) an=(an+1ll*C(qq[a], a-b)*dp[b])%mod;
        }
    }
    cout<<an;
}