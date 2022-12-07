#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    vector <int> sv[n];
    int st[n], w[n];
    for(int a=0; a<n; a++) st[a]=0, w[a]=inf;
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[v].push_back(u);
        st[u]++;
    }
    w[n-1]=0;
    set <pair <int, int>> se;
    se.insert({0, n-1});
    while(se.size())
    {
        int v=(*se.begin()).second;
        se.erase(se.begin());
        for(int a=0; a<sv[v].size(); a++)
        {
            int ne=sv[v][a];
            if(w[ne]>w[v]+st[ne])
            {
                se.erase({w[ne], ne});
                w[ne] = w[v]+st[ne];
                se.insert({w[ne], ne});
            }
            st[ne]--;
        }
    }
    cout<<w[0];
}