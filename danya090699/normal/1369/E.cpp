#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q[n];
    for(int a=0; a<n; a++) scanf("%d", &q[a]);
    vector <int> sv[n];
    int re[m][2];
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        q[u]--, q[v]--;
        sv[u].push_back(a);
        sv[v].push_back(a);
        re[a][0]=u, re[a][1]=v;
    }
    vector <int> sp, an;
    for(int a=0; a<m; a++)
    {
        if(q[re[a][0]]>=0 or q[re[a][1]]>=0)
        {
            sp.push_back(a);
        }
    }
    while(sp.size())
    {
        an.push_back(sp.back()+1);
        int v=re[sp.back()][0], u=re[sp.back()][1];
        sp.pop_back();
        if(q[v]>q[u]) swap(u, v);
        q[v]++, q[u]++;
        if(q[v]==0)
        {
            for(int a=0; a<sv[v].size(); a++)
            {
                int i=sv[v][a];
                int to=re[i][0];
                if(to==v) to=re[i][1];
                if(q[to]<0) sp.push_back(i);
            }
        }
    }
    if(an.size()==m)
    {
        reverse(an.begin(), an.end());
        cout<<"ALIVE\n";
        for(int a=0; a<m; a++) cout<<an[a]<<" ";
    }
    else cout<<"DEAD";
}