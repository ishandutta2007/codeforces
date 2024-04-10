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
        map<int,int> cnt;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            cnt[a]++;
        }
        set<array<int,2>> bad;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin >> a >> b;
            bad.insert({a,b});
        }
        map<int,vector<int>> opt;
        for(auto [a,c]:cnt) opt[c].push_back(a);
        ll res=0;
        for(auto &[ca,v]:opt)
        {
            for(auto &[cb,u]:opt)
            {
                if(ca>cb) continue;
                set<array<int,2>> vis;
                priority_queue<array<int,3>> q;
                int sv=v.size();
                int su=u.size();
                auto add=[&](int x,int y)
                {
                    if(x>=0&&y>=0&&!vis.contains({x,y}))
                    {
                        vis.insert({x,y});
                        q.push({v[x]+u[y],x,y});
                    }
                };
                add(sv-1,su-1);
                while(!q.empty())
                {
                    auto [sum,x,y]=q.top();
                    q.pop();
                    int tx=v[x],ty=u[y];
                    if(tx>ty) swap(tx,ty);
                    if(tx<ty&&!bad.contains({tx,ty}))
                    {
                        res=max(res,ll(ca+cb)*sum);
                        break;
                    }
                    add(x-1,y);
                    add(x,y-1);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}