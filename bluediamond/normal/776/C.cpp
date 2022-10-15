#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll k;
    cin >> k;

    vector<ll> sum(n);
    cin >> sum[0];

    for (int i = 1; i < n; i++)
    {
        ll x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    vector<ll> difs;
    if (abs(k) == 1)
    {
        if (k == 1)
        {
            difs = {1};
        }
        else
        {
            difs = {-1, 1};
        }
    }
    else
    {
        ll cur = 1;
        while (cur <= (ll) 1e15)
        {
            difs.push_back(cur);
            cur *= k;
        }
    }

    map<ll, int> f;
    f[0]++;
    ll ans = 0;

    for (auto &x : sum)
    {
        for (auto &d : difs)
        {
            ans += f[x - d];
        }
        f[x]++;
    }
    cout << ans << "\n";
}