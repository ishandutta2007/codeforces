#include <bits/stdc++.h>
using namespace std;
vector <int> *sv, sp;
bool *us;
void dfs(int v)
{
    us[v]=1;
    sp.push_back(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(us[ne]==0) dfs(ne);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, er=0;
    cin>>n>>m;
    int q[n];
    sv=new vector <int> [n], us=new bool[n];
    for(int a=0; a<n; a++)
    {
        us[a]=0, q[a]=0;
    }
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
        q[u]++, q[v]++;
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            dfs(a);
            //cout<<q[1]<<" ";
            for(int b=0; b<sp.size(); b++)
            {
                if(q[sp[b]]!=sp.size()-1) er=1;
            }
            sp.clear();
        }
    }
    if(er) cout<<"NO";
    else cout<<"YES";
}