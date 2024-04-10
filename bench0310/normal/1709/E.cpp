#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n+1,0);
    for(int i=1;i<=n;i++) cin >> c[i];
    vector<int> v[n+1];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> x(n+1,0);
    vector<int> sz(n+1,0);
    vector<int> big(n+1,0);
    function<void(int,int)> dfs=[&](int a,int p)
    {
        x[a]=(x[p]^c[a]);
        sz[a]=1;
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            sz[a]+=sz[to];
            if(sz[to]>sz[big[a]]) big[a]=to;
        }
    };
    dfs(1,0);
    int res=0;
    function<set<int>(int,int)> go=[&](int a,int p)->set<int>
    {
        set<int> s;
        if(big[a]!=0) s=go(big[a],a);
        bool bad=0;
        for(int to:v[a])
        {
            if(to==p||to==big[a]) continue;
            set<int> t=go(to,a);
            for(int y:t) bad|=(s.contains(y^c[a]));
            for(int y:t) s.insert(y);
        }
        bad|=(s.contains(x[a]^c[a]));
        s.insert(x[a]);
        if(bad)
        {
            res++;
            s.clear();
        }
        return s;
    };
    go(1,0);
    cout << res << "\n";
    return 0;
}