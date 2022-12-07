#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int q[2]={0, 0};
void dfs(int v, int pr, int h)
{
    if(sv[v].size()==1) q[h]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v, h^1);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n-1; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    dfs(0, 0, 0);
    if(q[0] and q[1]) cout<<"3 ";
    else cout<<"1 ";
    int ma=n-1;
    for(int a=0; a<n; a++)
    {
        int q=0;
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];
            if(sv[ne].size()==1) q++;
        }
        if(q>1) ma-=q-1;
    }
    cout<<ma;
}