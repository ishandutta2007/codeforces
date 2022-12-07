#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, inf=1e9;
vector <int> sv[sz];
set <int> us;
void dfs(int v)
{
    sort(sv[v].begin(), sv[v].end());
    sv[v].push_back(inf);
    reverse(sv[v].begin(), sv[v].end());
    us.erase(v);
    int yk=-1;
    while(us.upper_bound(yk)!=us.end())
    {
        int ne=(*us.upper_bound(yk));
        while(sv[v].back()<ne) sv[v].pop_back();
        if(sv[v].back()==ne) sv[v].pop_back(), yk=ne;
        else dfs(ne);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q=0;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<n; a++) us.insert(a);
    for(int a=0; a<n; a++)
    {
        if(us.find(a)!=us.end()) dfs(a), q++;
    }
    cout<<q-1;
}