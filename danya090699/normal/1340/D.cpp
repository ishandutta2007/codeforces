#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
vector <pair <int, int> > an;
int m=0;
void dfs(int v, int pr, int x)
{
    an.push_back({v, x});
    int chq=sv[v].size(), i=x;
    if(v!=1) chq--;

    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            if(i==m)
            {
                i=x-chq-1, an.push_back({v, i});
            }
            i++, dfs(ne, v, i), chq--;
        }
    }

    if(v!=1)
    {
        if(i!=x-1) an.push_back({v, x-1});
        an.push_back({pr, x});
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
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=1; a<=n; a++) m=max(m, int(sv[a].size()));
    dfs(1, 0, 0);
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
}