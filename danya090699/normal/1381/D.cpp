#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int dow[sz], up[sz], rt, A, B, len;
void dfs(int v, int pr, int h)
{
    if(v==B) len=h;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v, h+1);
    }
}
void dfs2(int v, int pr)
{
    dow[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs2(ne, v), dow[v]=max(dow[v], dow[ne]+1);
    }
}
void dfs3(int v, int pr)
{
    vector <int> sp;
    sp.push_back(up[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) sp.push_back(dow[ne]+1);
    }
    sort(sp.begin(), sp.end(), greater <int>());
    if(sp.size()>=3 and sp[2]>=len) rt=v;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            if(dow[ne]+1==sp[0]) up[ne]=sp[1]+1;
            else up[ne]=sp[0]+1;
            dfs3(ne, v);
        }
    }
}
int h[sz], dp[sz], pr[sz];
void dfs4(int v)
{
    dp[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr[v])
        {
            pr[ne]=v, h[ne]=h[v]+1, dfs4(ne), dp[v]=max(dp[v], dp[ne]+1);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n>>A>>B;
        A--, B--;
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        dfs(A, A, 0);
        dfs2(0, 0);
        up[0]=0, rt=-1, dfs3(0, 0);

        if(rt!=-1)
        {
            h[rt]=0, pr[rt]=rt, dfs4(rt);

            vector <int> path[2];
            path[0].push_back(A);
            path[1].push_back(B);
            while(path[0].back()!=path[1].back())
            {
                if(h[path[0].back()]>h[path[1].back()])
                {
                    path[0].push_back(pr[path[0].back()]);
                }
                else
                {
                    path[1].push_back(pr[path[1].back()]);
                }
            }
            reverse(path[0].begin(), path[0].end());
            reverse(path[1].begin(), path[1].end());

            int l[2]={path[0].size()-1, path[1].size()-1};
            while(l[0] and l[1])
            {
                bool ok=0;
                for(int i=0; i<2; i++)
                {
                    int v=path[i][l[i]];
                    int x=max(0, len-dp[v]-l[i]);
                    if(x<l[i^1]) l[i^1]=x, ok=1;
                }
                if(!ok) break;
            }
            if(l[0] and l[1]) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else cout<<"NO\n";

        for(int a=0; a<n; a++) sv[a].clear();
    }
}