#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
const ll INF = 1e18;

ll a[200002];
ll b[200002];
ll c[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        b[1] = a[1];
        c[1] = 1;
        int m = 1;
        for(int i=2;i<=n;i++)
        {
            if(a[i] != a[i-1])
            {
                m++;
                b[m] = a[i];
                c[m] = 1;
            }
            else
            {
                c[m]++;
            }
        }
        b[m+1] = INF;
        int ans = c[m];
        for(int i=1;i<m;i++)
        {
            ll x = b[i], y = b[i+1];
            int cnt = c[i], j = i + 1;
            while(j <= m)
            {
                j = lower_bound(b+1, b+m+1, 2*y - x) - b;
                y = b[j];
                cnt++;
            }
            ans = max(ans, cnt);
        }
        cout << n - ans << "\n";
    }
}