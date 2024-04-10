#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector a(n+1,vector(n+1,int(0)));
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin >> a[i][j];
    vector<int> res(n+1,0);
    vector<vector<array<int,3>>> now(n+2);
    vector<int> vis(n*n+1,0);
    for(int i=n;i>=1;i--)
    {
        vector<vector<array<int,3>>> nxt(n+2);
        for(int j=n;j>=1;j--)
        {
            vector<array<int,3>> v;
            v.push_back({a[i][j],i,j});
            for(auto [c,x,y]:nxt[j+1]) v.push_back({c,x,y});
            for(auto [c,x,y]:now[j+1]) v.push_back({c,x,y});
            for(auto [c,x,y]:now[j]) v.push_back({c,x,y});
            auto d=[&](array<int,3> c)->int{return max(c[1]-i,c[2]-j);};
            ranges::sort(v,[&](const auto &x,const auto &y){return (d(x)<d(y));});
            for(auto [c,x,y]:v)
            {
                if(vis[c]) continue;
                vis[c]=1;
                nxt[j].push_back({c,x,y});
                if((int)nxt[j].size()==q+1) break;
            }
            for(auto [c,x,y]:nxt[j]) vis[c]=0;
            int good=0;
            if((int)nxt[j].size()==q+1) good=min({n-i+1,n-j+1,d(nxt[j].back())});
            else good=min(n-i+1,n-j+1);
            res[good]++;
        }
        now=nxt;
    }
    for(int i=n-1;i>=1;i--) res[i]+=res[i+1];
    for(int i=1;i<=n;i++) cout << res[i] << "\n";
    return 0;
}