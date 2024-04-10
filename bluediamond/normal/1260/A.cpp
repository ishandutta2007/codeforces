#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll c, s;
        cin >> c >> s;
        vector<ll> all(c, s / c);
        s %= c;
        for (ll i = 0; i < s; i++)
        {
            all[i]++;
        }
        ll ans = 0;
        for (auto &x : all)
        {
            ans += x * x;
        }
        cout << ans << "\n";
    }
}