#include <bits/stdc++.h>
using namespace std;
int n, *co, an=0;
vector <int> *sv;
void dfs(int v, int pr)
{
    int cu=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            if(cu==co[v] or cu==co[pr]) cu++;
            if(cu==co[v] or cu==co[pr]) cu++;
            co[ne]=cu, cu++;
            dfs(ne, v);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    sv=new vector <int>[n], co=new int[n];
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    co[0]=1;
    dfs(0, 0);
    for(int a=0; a<n; a++) an=max(an, co[a]);
    cout<<an<<"\n";
    for(int a=0; a<n; a++) cout<<co[a]<<" ";
}