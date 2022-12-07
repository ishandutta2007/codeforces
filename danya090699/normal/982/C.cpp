#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int an=0;
bool dfs(int v, int pr)
{
    bool si=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            bool va=dfs(ne, v);
            if(va==0) an++;
            else si^=1;
        }
    }
    return si;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    if(dfs(0, -1)) cout<<-1;
    else cout<<an;
}