#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n], rsv[n];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), rsv[v].push_back(u);
    }
    int us[n], an[n], q=0;
    vector <int> sp;
    for(int a=0; a<n; a++)
    {
        us[a]=0, an[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            us[a]=1, sp.push_back(a);
            for(int b=0; b<sv[a].size(); b++) us[sv[a][b]]=1;
        }
    }
    while(sp.size())
    {
        int v=sp.back();
        for(int a=0; a<rsv[v].size(); a++) an[v]|=an[rsv[v][a]];
        an[v]^=1, q+=an[v];
        sp.pop_back();
    }
    cout<<q<<"\n";
    for(int a=0; a<n; a++) if(an[a]) printf("%d ", a+1);
}