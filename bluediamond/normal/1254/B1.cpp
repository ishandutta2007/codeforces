#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> get_primes(ll n)
{
    vector<ll> ans;
    for (ll d = 2; d * d <= n; d++)
    {
        bool is = 0;
        while (n % d == 0)
        {
            n /= d;
            is = 1;
        }
        if (is)
        {
            ans.push_back(d);
        }
    }
    if (n > 1)
    {
        ans.push_back(n);
    }
    return ans;
}

ll test(vector<ll> a, ll k)
{
    int n = (int) a.size();
    for (int i = 1; i < n; i++)
    {
        a[i] += a[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(a[i] % k, k - a[i] % k);
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll sum = 0;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == 1)
    {
        cout << "-1\n";
        return 0;
    }
    ll ans = (ll) 1e18;
    vector<ll> t = get_primes(sum);
    for (auto &x : t)
    {
        ans = min(ans, test(a, x));
    }
    cout << ans << "\n";
}