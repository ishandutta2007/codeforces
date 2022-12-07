#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <pair <int, int> > sv[sz];
int n, k;
int dow[sz], up[sz];
void dfs(int v, int pr)
{
    dow[v]=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, d=sv[v][a].second;
        if(ne!=pr)
        {
            dfs(ne, v), dow[v]=max(dow[v], dow[ne]+d);
        }
    }
}
void dfs2(int v, int pr)
{
    multiset <int, greater <int> > se;
    se.insert(up[v]);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, d=sv[v][a].second;
        if(ne!=pr) se.insert(dow[ne]+d);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, d=sv[v][a].second;
        if(ne!=pr)
        {
            se.erase(se.find(dow[ne]+d));
            up[ne]=(*se.begin())+d;
            dfs2(ne, v);
            se.insert(dow[ne]+d);
        }
    }
}
int dp[sz], ok;
void dfs3(int v, int pr, int x)
{
    int q=0, bad=0, su=0;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, d=sv[v][a].second;
        if(ne!=pr)
        {
            dfs3(ne, v, x);

            if(dp[ne]==-1) bad=1;
            else
            {
                if(dp[ne])
                {
                    q++, su+=dp[ne];
                }
                else
                {
                    if(dow[ne]+d>x)
                    {
                        q++, su++;
                    }
                }
            }
        }
    }
    if(bad) dp[v]=-1;
    else
    {
        if(q)
        {
            if(q==1) dp[v]=su+1;
            else dp[v]=-1;
        }

        if(up[v]<=x and q<3 and su+1<=k) ok=1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v, va;
        scanf("%d%d%d", &u, &v, &va);
        u--, v--;
        sv[u].push_back(make_pair(v, va));
        sv[v].push_back(make_pair(u, va));
    }
    dfs(0, -1);
    up[0]=0, dfs2(0, -1);


    //for(int a=0; a<n; a++) cout<<up[a]<<" ";
    int l=-1, r=2e9;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        for(int a=0; a<n; a++) dp[a]=0;
        ok=0, dfs3(0, -1, mid);
        if(ok) r=mid;
        else l=mid;
    }
    cout<<r;
}