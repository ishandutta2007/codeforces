#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, s[5005], a[5005], p[5005], siz[5005], Max[5005];

int get(int x)
{
    if(x == p[x])
        return x;

    p[x] = get(p[x]);
    return p[x];
}

void unite(int x, int y)
{
    x = get(x);
    y = get(y);

    if(x == y)
        return;

    if(siz[x] > siz[y])
        swap(x, y);

    p[x] = y;
    siz[y] += siz[x];
    Max[y] = max(Max[y], Max[x]);
}

int f(int y)
{
    if(y + s[y] >= n)
        return y + s[y];

    return Max[get(y + s[y])];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> s[i];

        for(int i = 0; i <= n; i++)
        {
            p[i] = i;
            siz[i] = 1;
            Max[i] = i;
        }

        for(int i = 0; i < n; i++)
            if(s[i] == 1)
                unite(i, i + 1);

        int y = Max[get(0)];

        int x = 0, ans = 0;

        while(y < n)
        {
            if(f(y) >= n)
            {
                ans += f(y) - n + 1;
                s[y] -= f(y) - n + 1;

                if(y == n - 1)
                {
                    s[y] = 1;
                    ans--;
                }

                if(s[y] == 1)
                    unite(y, y + 1);
            }
            else
            {
                ans++;

                while(y < n)
                {
                    int z = f(y);
                    s[y]--;

                    if(s[y] == 1)
                        unite(y, y + 1);

                    y = z;
                }
            }

            y = Max[get(0)];
        }

        cout << ans << "\n";
    }
}