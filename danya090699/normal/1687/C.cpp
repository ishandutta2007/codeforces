#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
set <int> se;
int add[sz];
vector <int> sv[sz];
void dfs(int v)
{
    se.erase(v);
    for(int a=0; a<sv[v].size(); a++)
    {
        int to=sv[v][a];
        if(se.find(to)==se.end())
        {
            int l=min(v, to), r=max(v, to);
            add[l]+=1, add[r]-=1;
            while(1)
            {
                auto it=se.lower_bound(l);
                if(it!=se.end() and (*it)<=r) dfs(*it);
                else break;
            }
        }
    }
}
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        long long pref[2][n+1];
        for(int i=0; i<2; i++)
        {
            pref[i][0]=0;
            for(int a=1; a<=n; a++)
            {
                scanf("%lld", &pref[i][a]);
                pref[i][a]+=pref[i][a-1];
            }
        }
        for(int a=0; a<=n; a++) add[a]=0;
        for(int a=0; a<m; a++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            l--;
            sv[l].push_back(r);
            sv[r].push_back(l);
        }
        for(int a=0; a<n; a++)
        {
            if(pref[0][a+1]-pref[0][a] == pref[1][a+1]-pref[1][a])
            {
                sv[a].push_back(a+1);
                sv[a+1].push_back(a);
            }
        }
        for(int a=0; a<=n; a++) se.insert(a);
        for(int a=0; a<=n; a++)
        {
            if(pref[0][a]==pref[1][a] and se.find(a)!=se.end()) dfs(a);
        }
        int ok=1;
        for(int a=0; a<n; a++)
        {
            if(a) add[a]+=add[a-1];
            if(add[a]==0) ok=0;
        }
        printf(ok ? "YES\n": "NO\n");

        for(int a=0; a<=n; a++) sv[a].clear();
        se.clear();
    }
}