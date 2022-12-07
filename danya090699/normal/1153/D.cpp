#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
vector <int> sv[sz];
int si[sz], va[sz], f[sz];
void dfs(int v)
{
    if(sv[v].size()==0) si[v]=1, va[v]=1;
    else
    {
        int mi=1e9;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            dfs(ne), si[v]+=si[ne];
            if(f[v]==0) va[v]+=va[ne]-1;
            else mi=min(mi, si[ne]-va[ne]);
        }
        if(f[v]==0) va[v]++;
        else va[v]=si[v]-mi;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++) scanf("%d", &f[a]);
    for(int a=1; a<n; a++)
    {
        int pr;
        scanf("%d", &pr);
        pr--;
        sv[pr].push_back(a);
    }
    dfs(0);
    cout<<va[0];
}