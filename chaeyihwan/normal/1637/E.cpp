#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

ll a[300002];
ll cnt[300002], v[300002];

vector<ll> adj[300002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) adj[i].clear();

        sort(a+1, a+n+1);

        int k = 1;
        cnt[1] = 1;
        v[1] = a[1];
        for(int i=2;i<=n;i++)
        {
            if(a[i] == a[i-1]) cnt[k]++;
            else
            {
                ++k;
                cnt[k] = 1;
                v[k] = a[i];
            }
        }

        for(int i=1;i<=k;i++) adj[cnt[i]].push_back(v[i]);
        vector<int> nonempty;

        for(int i=1;i<=n;i++) if(!adj[i].empty()) nonempty.push_back(i);

        map<pair<ll, ll>, int> no;
        for(int i=1;i<=m;i++)
        {
            ll a, b;
            cin >> a >> b;
            no[{a, b}] = 1;
        }

        for(int i=1;i<=n;i++) sort(adj[i].rbegin(), adj[i].rend());

        ll ans = 0;
        for(int i=1;i<=k;i++)
        {
            for(ll j : nonempty)
            {
                for(ll x : adj[j])
                {
                    if(v[i] >= x) break;
                    if(!no[{v[i], x}])
                    {
                        ans = max(ans, (cnt[i]+j)*(x+v[i]));
                        break;
                    }
                }
            }
        }

        cout << ans << "\n";
    }
}