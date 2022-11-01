#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    set<int> v[k+1];
    vector<int> in(k+1,0);
    vector<int> out(k+1,0);
    auto add_edge=[&](int a,int b)
    {
        if(v[a].find(b)!=v[a].end()) return;
        v[a].insert(b);
        in[b]++;
        out[a]++;
    };
    for(int i=1;i<=n;i++)
    {
        int c;
        cin >> c;
        int s;
        cin >> s;
        for(int j=2;j<=c;j++)
        {
            int a;
            cin >> a;
            add_edge(s,a);
            s=a;
        }
    }
    vector<bool> vis(k+1,0);
    vector<int> cnt(m+1,0);
    for(int i=1;i<=k;i++)
    {
        if(vis[i]||in[i]>=1||out[i]>1) continue;
        bool ok=1;
        int a=i;
        int len=0;
        while(1)
        {
            ok&=(in[a]<=1&&out[a]<=1&&!vis[a]);
            if(!ok) break;
            vis[a]=1;
            len++;
            if(out[a]==0) break;
            a=(*v[a].begin());
        }
        if(ok&&len<=m) cnt[len]++;
    }
    vector<array<int,2>> opt;
    for(int i=1;i<=m;i++) if(cnt[i]>0) opt.push_back({i,cnt[i]});
    const ll mod=998244353;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> dp(m+1,0);
    dp[0]=1;
    for(int i=0;i<=m;i++)
    {
        for(auto [c,o]:opt) if(i+c<=m) dp[i+c]=add(dp[i+c],mul(o,dp[i]));
    }
    cout << dp[m] << "\n";
    return 0;
}