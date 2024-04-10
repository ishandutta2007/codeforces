#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int n, q, a[100005], lp[100005], r[100005], k[100005], up[100005][25];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 2; i < 100005; i++)
        if(lp[i] == 0)
        {
            lp[i] = i;

            for(int j = i * i; j < 100005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;
        }

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int f = 0;

    for(int i = 0; i < n; i++)
    {
        if(i > 0)
            r[i] = r[i - 1];
        else r[i] = -1;

        while(r[i] < n && f == 0)
        {
            r[i]++;

            int x = a[r[i]];

            while(x > 1)
            {
                int y = lp[x];
                k[y]++;

                if(k[y] == 2)
                    f++;

                while(x % y == 0)
                    x /= y;
            }
        }

        int x = a[i];

        while(x > 1)
        {
            int y = lp[x];
            k[y]--;

            if(k[y] == 1)
                f--;

            while(x % y == 0)
                x /= y;
        }
    }

    r[n] = n;

    for(int i = 0; i <= n; i++)
        up[i][0] = r[i];

    for(int j = 1; j <= 20; j++)
        for(int i = 0; i <= n; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];

    while(q--)
    {
        int L, R;
        cin >> L >> R;

        L--;

        int ans = 0;

        for(int j = 20; j >= 0; j--)
        {
            if(up[L][j] < R)
            {
                ans += (1ll << j);

                L = up[L][j];
            }
        }

        cout << ans + 1 << "\n";
    }
}