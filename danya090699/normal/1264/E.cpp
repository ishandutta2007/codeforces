#include <bits/stdc++.h>
using namespace std;
const int sz=55;
int n, m, sm[sz][sz], us[sz], us2[sz][sz], st[sz], x;
bool dfs(int v)
{
    us[v]=1;
    if(st[v]<x-1) return true;
    for(int a=0; a<n; a++)
    {
        if(sm[v][a] and us[a]==0 and us2[v][a]==0)
        {
            if(dfs(a))
            {
                sm[v][a]=0, sm[a][v]=1;
                st[v]--, st[a]++;
                return true;
            }
        }
    }
    return false;
}
bool comp(int a, int b){return st[a]<st[b];}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--;
        us2[u][v]=1, us2[v][u]=1, sm[u][v]=1;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++) if(!us2[a][b]) sm[a][b]=1;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) if(sm[a][b]) st[a]++;
    }
    vector <int> sp;
    for(int a=0; a<n; a++) sp.push_back(a);
    while(sp.size())
    {
        sort(sp.begin(), sp.end(), comp);
        for(int a=0; a<n; a++) us[a]=0;
        x=st[sp.back()];
        if(!dfs(sp.back())) sp.pop_back();
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++) cout<<sm[a][b];
        cout<<"\n";
    }
}