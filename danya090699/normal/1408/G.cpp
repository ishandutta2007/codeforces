#include <bits/stdc++.h>
using namespace std;
const int mod=998244353, sz=1510;
vector <int> sv[sz*2];
int n, us[sz*2], dp[sz*2][sz], si[sz*2];
void dfs(int v)
{
    int dp2[n+1];
    for(int a=0; a<=n; a++) dp2[a]=0;
    dp[v][0]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        dfs(ne);
        for(int b=0; b<=si[v]; b++)
        {
            for(int c=1; c<=si[ne]; c++)
            {
                dp2[b+c]=(dp2[b+c]+1ll*dp[v][b]*dp[ne][c])%mod;
            }
        }
        si[v]+=si[ne];
        for(int b=0; b<=si[v]; b++) dp[v][b]=dp2[b], dp2[b]=0;
    }
    dp[v][1]=1;
    if(sv[v].size()==0) si[v]=1;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    int re[n*(n-1)/2][2], com[n], rq[n], cl[n], q=n;
    vector <int> sp[n];
    for(int a=0; a<n; a++)
    {
        com[a]=a, cl[a]=a, sp[a].push_back(a), rq[a]=0;

        for(int b=0; b<n; b++)
        {
            int w;
            scanf("%d", &w);
            if(w) re[w-1][0]=a, re[w-1][1]=b;
        }
    }

    for(int a=0; a<n*(n-1)/2; a++)
    {
        int u=com[re[a][0]], v=com[re[a][1]];

        if(u!=v)
        {
            if(sp[u].size()<sp[v].size()) swap(u, v);

            rq[u]+=rq[v];

            while(sp[v].size())
            {
                com[sp[v].back()]=u;
                sp[u].push_back(sp[v].back());
                sp[v].pop_back();
            }
        }
        rq[u]++;

        if(rq[u]==sp[u].size()*(sp[u].size()-1)/2)
        {
            for(int b=0; b<sp[u].size(); b++)
            {
                int v=sp[u][b];
                if(!us[cl[v]])
                {
                    sv[q].push_back(cl[v]);
                    us[cl[v]]=1;
                }
                cl[v]=q;
            }
            q++;
        }
    }
    dfs(q-1);
    for(int a=1; a<=n; a++) cout<<dp[q-1][a]<<" ";
}