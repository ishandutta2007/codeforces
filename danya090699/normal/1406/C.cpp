#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int n, si[sz], x1, y1, x2, y2;
void dfs(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v), si[v]+=si[ne];
            if(si[ne]*2==n)
            {
                for(int b=0; b<sv[ne].size(); b++)
                {
                    int u=sv[ne][b];
                    if(u!=v)
                    {
                        x1=u+1, y1=ne+1, x2=u+1, y2=v+1;
                    }
                }
            }
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            x1=u, y1=v, x2=u, y2=v;
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        dfs(0, 0);
        printf("%d %d\n%d %d\n", x1, y1, x2, y2);

        for(int a=0; a<n; a++) sv[a].clear();
    }
}