#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<vector<array<int,2>>> v(n+1);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
    }
    vector<int> u(n+1,0);
    vector<int> depth(n+1,-1);
    vector<int> cnte(n+1,0);
    vector<int> cnto(n+1,0);
    int even=0;
    int one_even=0;
    vector<int> now;
    auto dfs=[&](auto &&self,int a,int p)->void
    {
        if(p!=0) now.push_back(a);
        depth[a]=depth[p]+1;
        for(auto [to,id]:v[a])
        {
            if(id==u[a]) continue;
            if(depth[to]==-1)
            {
                u[to]=id;
                self(self,to,a);
                cnte[a]+=cnte[to];
                cnto[a]+=cnto[to];
            }
            else
            {
                int t=(depth[a]-depth[to])&1;
                even+=(t==0&&(depth[a]>depth[to]));
                if(t==0) one_even=id;
                (t==0?cnte[a]:cnto[a])+=(depth[a]>depth[to]?1:-1);
            }
        }
    };
    vector<vector<int>> res;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]!=-1) continue;
        dfs(dfs,i,0);
        vector<int> opt;
        for(int a:now) if(cnte[a]==even&&cnto[a]==0) opt.push_back(u[a]);
        if(even==1) opt.push_back(one_even);
        if(even>=1) res.push_back(opt);
        even=0;
        now.clear();
    }
    if(res.size()==0)
    {
        res.push_back({});
        for(int i=1;i<=m;i++) res.back().push_back(i);
    }
    vector<int> fin=(res.size()==1?res[0]:vector<int>());
    ranges::sort(fin);
    cout << fin.size() << "\n";
    for(int e:fin) cout << e << " ";
    cout << "\n";
    return 0;
}