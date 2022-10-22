#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;
ll a[1000002], b[500002];

int gcd(int x, int y)
{
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=m;i++) cin >> b[i];

        int g = b[1];
        for(int i=2;i<=m;i++) g = gcd(g, b[i]);

        ll ans = 0;
        if(g == 1)
        {
            for(int i=1;i<=n;i++) ans += abs(a[i]);
            cout << ans << "\n";
            continue;
        }
        ll ans1 = 0, ans2 = 0;
        for(int i=1;i<=g;i++)
        {
            vector<int> v;
            int cnt = 0;
            for(int j=i;j<=n;j+=g)
            {
                if(a[j] < 0) cnt++;
                v.push_back(abs(a[j]));
            }
            sort(v.rbegin(), v.rend());
            int m = v.size();
            for(int j=0;j<m-1;j++) ans1 += v[j];
            if(cnt%2) ans1 -= v[m-1];
            else ans1 += v[m-1];
        }

        for(int i=1;i<=g;i++) a[i] = -a[i];
        for(int i=1;i<=g;i++)
        {
            vector<int> v;
            int cnt = 0;
            for(int j=i;j<=n;j+=g)
            {
                if(a[j] < 0) cnt++;
                v.push_back(abs(a[j]));
            }
            sort(v.rbegin(), v.rend());
            int m = v.size();
            for(int j=0;j<m-1;j++) ans2 += v[j];
            if(cnt%2) ans2 -= v[m-1];
            else ans2 += v[m-1];
        }
        cout << max(ans1, ans2) << "\n";
    }
}