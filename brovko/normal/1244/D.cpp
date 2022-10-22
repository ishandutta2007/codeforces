#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, c[100005][3], u, v, d[100005], e[100005], ind0, ind1;
vector <int> g[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> c[i][0];
    for(int i=0;i<n;i++)
        cin >> c[i][1];
    for(int i=0;i<n;i++)
        cin >> c[i][2];
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
        if(g[u].size()>2 || g[v].size()>2)
        {
            cout << -1;
            return 0;
        }
    }
    int l=-1;
    for(int i=0;i<n;i++)
        if(g[i].size()==1)
            l=i;
    d[0]=l;
    for(int i=0;i<n-1;i++)
    {
        if(i==0 || g[d[i]][0]!=d[i-1])
            d[i+1]=g[d[i]][0];
        else d[i+1]=g[d[i]][1];
    }
    int s=0;
    int ans=1e18;
    for(e[d[0]]=0;e[d[0]]<3;e[d[0]]++)
        for(e[d[1]]=0;e[d[1]]<3;e[d[1]]++)
            if(e[d[0]]!=e[d[1]])
    {
        s=c[d[0]][e[d[0]]]+c[d[1]][e[d[1]]];
        for(int i=2;i<n;i++)
            {
                e[d[i]]=3-e[d[i-1]]-e[d[i-2]];
                s+=c[d[i]][e[d[i]]];
            }
        if(s<ans)
        {
            ans=s;
            ind0=e[d[0]];
            ind1=e[d[1]];
        }
    }

    cout << ans << endl;
    e[d[0]]=ind0;
    e[d[1]]=ind1;

    s=c[d[0]][e[d[0]]]+c[d[1]][e[d[1]]];
        for(int i=2;i<n;i++)
            {
                e[d[i]]=3-e[d[i-1]]-e[d[i-2]];
                s+=c[d[i]][e[d[i]]];
            }
        if(s<ans)
        {
            ans=s;
            ind0=e[d[0]];
            ind1=e[d[1]];
        }

    for(int i=0;i<n;i++)
        cout << e[i]+1 << ' ';
}