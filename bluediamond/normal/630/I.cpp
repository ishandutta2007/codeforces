#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll pw(ll a, int b)
{
        ll r = 1;
        while (b)
        {
                if (b & 1)
                        r = r * a;
                a = a * a;
                b >>= 1;
        }
        return r;
}

ll func(int x)
{
        if (x == 0)
                return 1;
        else
        {
                return 3 * pw(4, x - 1);
        }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);

        ll n;
        cin >> n;
        ll total = 2 * n - 2;
        ll res = 0;
        for (int i = 1; i + n - 1 <= total; i++)
        {
                int j = i + n - 1;
                res += 4 * func(i - 1) * func(total - j);
        }
        cout << res << "\n";

        return 0;
}