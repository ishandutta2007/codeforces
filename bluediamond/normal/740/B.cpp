#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100 + 7;
int n, m;
ll s[N], ans = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        s[i] = s[i - 1] + x;
    }

    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        ll val = s[r] - s[l - 1];
        if (val > 0)
        {
            ans += val;
        }
    }
    cout << ans << "\n";

}