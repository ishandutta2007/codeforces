#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll l = 0, r = (ll) 1e9, ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 + 1 <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << n - ans * (ans + 1) / 2 << "\n";

}