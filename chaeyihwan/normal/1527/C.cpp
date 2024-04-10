#include <bits/stdc++.h>

using namespace std;
#define int long long
#define ll __int128_t

int a[100002];
vector<ll> v[100002];

main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        map<ll, ll> m;
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=n;i++) v[i].clear();
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            if(m[a[i]])
            {
                v[m[a[i]]].push_back(i);
            }
            else
            {
                m[a[i]] = ++cnt;
                v[cnt].push_back(i);
            }
        }
        ll ans = 0;
        for(ll i=1;i<=cnt;i++)
        {
            ll k = v[i].size();
            ll sum = 0, sqsum = 0, tsum = 0;
            for(ll j=0;j<k;j++)
            {
                sum += v[i][j];
                sqsum += v[i][j] * v[i][j];
                tsum += v[i][j] * (k-j-1);
            }

            ans += (n+1)*tsum - (sum*sum - sqsum)/2;
        }

        assert(ans <= 1e19);

        cout << (long long)ans << "\n";
    }
}