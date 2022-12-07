#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> sv[sz];
int us[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    set <int> se;
    se.insert(0);
    while(se.size())
    {
        int v=*se.begin();
        printf("%d ", v+1);
        se.erase(se.begin());
        us[v]=1;
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(us[ne]==0) se.insert(ne);
        }
    }
}