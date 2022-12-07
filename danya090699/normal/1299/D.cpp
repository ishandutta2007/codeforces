#include <bits/stdc++.h>
#define uint unsigned int
using namespace std;
const int sz=1e3, sz2=1e5+10, mod=1e9+7;
int nex[sz][32], sm[sz][sz];
uint nmask[sz][32];
uint f(uint mask, int x)
{
    uint re=mask|(1<<x);
    for(int i=0; i<32; i++)
    {
        if(mask&(1<<i)) re|=(1<<(i^x));
    }
    return re;
}

vector <pair <int, int> > sv[sz2];
int h[sz2], s, near[sz2], dp[sz], dp2[sz];
void dfs(int v, int pr)
{
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, w=sv[v][a].second;
        if(ne and near[ne]==-1)
        {
            if(h[ne]==-1) h[ne]=h[v]^w, dfs(ne, v);
            else if(v<ne and ne!=pr)
            {
                s=nex[s][h[v]^h[ne]^w];
            }
        }
    }
}

int SUM(int x, int y)
{
    return (x+y<mod) ? x+y : x+y-mod;
}
main()
{
    //freopen("input.txt", "r", stdin);
    map <uint, int> ma;
    ma[0]=0;
    queue <int> qu;
    qu.push(0);
    while(qu.size())
    {
        uint v=qu.front();
        for(int i=0; i<32; i++)
        {
            uint ne=f(v, i);
            if(ma.find(ne)==ma.end())
            {
                ma[ne]=0;
                qu.push(ne);
            }
        }
        qu.pop();
    }
    int q=0;
    uint mask[ma.size()];
    for(auto it=ma.begin(); it!=ma.end(); it++) mask[q]=(*it).first, (*it).second=q++;

    for(int a=0; a<q; a++)
    {
        for(int i=0; i<32; i++)
        {
            nmask[a][i]=f(mask[a], i);
            nex[a][i]=ma[nmask[a][i]];
        }
    }

    for(int a=0; a<q; a++)
    {
        for(int b=0; b<q; b++)
        {
            uint re=mask[a];
            for(int i=0; i<32; i++)
            {
                if(mask[b]&(1<<i)) re=re|nmask[a][i];
            }
            sm[a][b]=ma[re];
        }
    }

    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--, v--;
        sv[u].push_back({v, w});
        sv[v].push_back({u, w});
    }
    for(int a=0; a<n; a++) h[a]=-1, near[a]=-1;
    for(int a=0; a<sv[0].size(); a++)
    {
        near[sv[0][a].first]=sv[0][a].second;
    }
    dp[0]=1;
    for(int a=0; a<n; a++)
    {
        if(near[a]!=-1)
        {
            s=0;

            int a2=-1, add;
            for(int b=0; b<sv[a].size(); b++)
            {
                int ne=sv[a][b].first, w=sv[a][b].second;
                if(near[ne]!=-1) a2=ne, add=near[a]^near[ne]^w;
            }

            near[a]=-1, h[a]=0, dfs(a, a);
            if(a2!=-1) near[a2]=-1, h[a2]=0, dfs(a2, a2);

            for(int b=0; b<q; b++)
            {
                dp2[b]=SUM(dp2[b], dp[b]);

                int to=sm[b][s];

                dp2[to]=SUM(dp2[to], dp[b]);

                if(a2!=-1)
                {
                    dp2[to]=SUM(dp2[to], dp[b]);

                    to=nex[to][add];

                    dp2[to]=SUM(dp2[to], dp[b]);
                }
            }

            for(int b=0; b<q; b++) dp[b]=dp2[b], dp2[b]=0;
        }
    }
    int an=0;
    for(int a=0; a<q; a++) if((mask[a]&1)==0) an=SUM(an, dp[a]);
    cout<<an;
}