#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7, sz=1e5+10;
vector <int> sv[sz], sp;
int n, si[sz];
void dfs(int v, int pr)
{
    si[v]=1;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr)
        {
            dfs(ne, v), si[v]+=si[ne], sp.push_back(si[ne]*(n-si[ne]));
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
            scanf("%lld%lld", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        dfs(0, 0);
        sort(sp.begin(), sp.end());
        int m;
        cin>>m;
        vector <int> w;
        if(m<n-1) w.resize(n-1-m, 1);
        for(int a=0; a<m; a++)
        {
            int x;
            scanf("%lld", &x);
            w.push_back(x);
        }
        sort(w.begin(), w.end());
        while(w.size()>n-1)
        {
            int x=w.back();
            w.pop_back();
            w.back()=w.back()*x%mod;
        }
        int an=0;
        for(int a=0; a<n-1; a++)
        {
            sp[a]%=mod;
            an=(an+sp[a]*w[a])%mod;
        }
        printf("%lld\n", an);

        sp.clear();
        for(int a=0; a<n; a++) sv[a].clear();
    }
}