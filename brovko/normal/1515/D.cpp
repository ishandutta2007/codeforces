#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define pii pair <int, int>

using namespace std;

int t, n, l, r, a[200005], kl[200005], kr[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> l >> r;

        for(int i = 0; i <= n; i++)
        {
            kl[i] = 0;
            kr[i] = 0;
        }

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(l < r)
        {
            for(int i = 0; i < n / 2; i++)
                swap(a[i], a[n - 1 - i]);

            swap(l, r);
        }

        for(int i = 0; i < n; i++)
        {
            if(i < l)
                kl[a[i]]++;
            else kr[a[i]]++;
        }

        int ans = 0, p = 0;

        for(int i = 0; i <= n; i++)
        {
            int x = min(kl[i], kr[i]);

            kl[i] -= x;
            kr[i] -= x;

            int y = kl[i] / 2;

            p += y;
            kl[i] -= 2 * y;

            ans += kl[i];
        }

        int z = min((l - r) / 2, p);

        ans += z + 2 * max(0ll, p - z);

        cout << ans << "\n";
    }
}