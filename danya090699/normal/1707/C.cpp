#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, inf=1e9;
vector <int> os[sz], st, v2list;
vector <pair <int, int>> sv[sz];
int us[sz], tin[sz], timer=0, si[sz], bad[sz], h[sz];
void dfs(int v, int pr)
{
    h[v]=st.size();
    st.push_back(v);
    tin[v]=timer++;
    si[v]=1;
    for(int a=0; a<os[v].size(); a++)
    {
        int ne=os[v][a];
        if(ne != pr)
        {
            dfs(ne, v);
            si[v]+=si[ne];
        }
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a].first, i=sv[v][a].second;
        if(us[i]==0 and tin[ne]<tin[v])
        {
            if(h[ne]!=-1)
            {
                int v2=st[h[ne]+1];
                v2list.push_back(v2);
                bad[tin[v]]-=1;
                bad[tin[v]+si[v]]+=1;
            }
            else
            {
                bad[0]+=1;
                bad[tin[ne]]-=1;
                bad[tin[ne]+si[ne]]+=1;
                bad[tin[v]]-=1;
                bad[tin[v]+si[v]]+=1;
            }
        }
    }
    st.pop_back();
    h[v]=-1;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back({v, a+1});
        sv[v].push_back({u, a+1});
    }
    set <pair <int, int>> se;
    int di[n], pr[n];
    for(int a=1; a<n; a++) di[a]=inf;
    di[0]=0;
    se.insert({0, 0});
    while(se.size())
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        if(v)
        {
            os[v].push_back(pr[v]);
            os[pr[v]].push_back(v);
            us[di[v]]=1;
        }
        di[v]=0;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a].first, w=sv[v][a].second;
            if(w<di[ne])
            {
                se.erase({di[ne], ne});
                di[ne]=w;
                pr[ne]=v;
                se.insert({di[ne], ne});
            }
        }
    }
    for(int a=0; a<n; a++) tin[a]=inf;
    dfs(0, -1);
    for(int a=0; a<v2list.size(); a++)
    {
        int v2 = v2list[a];
        bad[tin[v2]]+=1;
        bad[tin[v2]+si[v2]]-=1;
    }
    for(int a=1; a<n; a++) bad[a]+=bad[a-1];
    for(int a=0; a<n; a++) printf(bad[tin[a]] ? "0" : "1");
}