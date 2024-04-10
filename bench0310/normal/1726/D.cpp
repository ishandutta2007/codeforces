#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<array<int,2>> edges(m);
        for(auto &[a,b]:edges) cin >> a >> b;
        vector<int> p(n+1,0);
        for(int i=1;i<=n;i++) p[i]=i;
        vector<int> sz(n+1,1);
        auto find_set=[&](auto &&self,int a)->int
        {
            if(a==p[a]) return a;
            else return p[a]=self(self,p[a]);
        };
        auto merge_sets=[&](int a,int b)->bool
        {
            a=find_set(find_set,a);
            b=find_set(find_set,b);
            if(a==b) return 0;
            if(sz[a]<sz[b]) swap(a,b);
            p[b]=a;
            sz[a]+=sz[b];
            return 1;
        };
        string col(m,'0');
        vector<array<int,3>> o;
        vector<vector<array<int,2>>> v(n+1);
        for(int i=0;i<m;i++)
        {
            auto [a,b]=edges[i];
            if(merge_sets(a,b))
            {
                col[i]='1';
                v[a].push_back({b,i});
                v[b].push_back({a,i});
            }
            else o.push_back({a,b,i});
        }
        if(o.size()==3)
        {
            set<int> s;
            for(auto [a,b,e]:o)
            {
                s.insert(a);
                s.insert(b);
            }
            if(s.size()==3)
            {
                auto [x,y,f]=o[0];
                col[f]='1';
                auto dfs=[&](auto &&self,int a,int u)->void
                {
                    for(auto [to,e]:v[a])
                    {
                        if(to==u) continue;
                        if(to==y) col[e]='0';
                        self(self,to,a);
                    }
                };
                dfs(dfs,x,0);
            }
        }
        cout << col << "\n";
    }
    return 0;
}