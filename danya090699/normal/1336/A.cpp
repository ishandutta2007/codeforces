#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int ar[sz], si[sz];
void dfs(int v, int pr, int h)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v, h+1), si[v]+=si[ne];
        }
    }
    ar[v]=h-(si[v]-1);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0, 0);
    sort(ar, ar+n, greater <int>());
    long long an=0;
    for(int a=0; a<k; a++) an+=ar[a];
    cout<<an;
}