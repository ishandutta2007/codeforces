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
        int n;
        cin >> n;
        vector<ll> l(n+1,0);
        vector<ll> r(n+1,0);
        for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<array<ll,2>> dp(n+1,{0,0});
        function<void(int,int)> dfs=[&](int a,int p)
        {
            for(int to:v[a])
            {
                if(to==p) continue;
                dfs(to,a);
                dp[a][0]+=max(dp[to][0]+abs(l[a]-l[to]),dp[to][1]+abs(l[a]-r[to]));
                dp[a][1]+=max(dp[to][0]+abs(r[a]-l[to]),dp[to][1]+abs(r[a]-r[to]));
            }
        };
        dfs(1,0);
        cout << max(dp[1][0],dp[1][1]) << "\n";
    }
    return 0;
}