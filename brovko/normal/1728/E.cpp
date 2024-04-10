#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

pair <int, int> solve(int x, int y)
{
    int ax = 1, bx = 0, ay = 0, by = 1;

    while(x != 0)
    {
        int k = y / x;
        ay -= k * ax;
        by -= k * bx;
        y %= x;

        swap(x, y);
        swap(ax, ay);
        swap(bx, by);
    }

    return make_pair(ay, by);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector <int> a(n), b(n);

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    vector <int> d(n);

    for(int i = 0; i < n; i++)
        d[i] = b[i] - a[i];

    sort(d.rbegin(), d.rend());

    vector <int> ps(n + 1);

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + d[i];

    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += a[i];

    int q;
    cin >> q;

    while(q--)
    {
        int x, y;
        cin >> x >> y;

        pair <int, int> p = solve(x, y);

        int g = __gcd(x, y);
        int px = x / g, py = y / g;

        int kx = p.f, ky = p.s;

        if(n % g)
        {
            cout << "-1\n";
            continue;
        }

        int pn = n / g;
        kx *= pn;
        ky *= pn;

        if(kx < 0)
        {
            int k = (-kx + py - 1) / py;
            kx += k * py;
            ky -= k * px;
        }

        if(ky < 0)
        {
            int k = (-ky + px - 1) / px;
            kx -= k * py;
            ky += k * px;
        }

        if(kx < 0)
            cout << "-1\n";
        else
        {
            int mny, mxy;

            mny = ky % px;
            mxy = ky + kx / py * px;

//            cout << mny << ' ' << mxy << "\n";

            int ans = -1e18;

            int L = mny, R = mxy;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(d[M * y] >= 0)
                    L = M;
                else R = M;
            }

            L -= ky % px;
            R -= ky % px;

            L = L / px * px;
            R = (R + px - 1) / px * px;

            L += ky % px;
            R += ky % px;

            L *= y;
            R *= y;

            ans = max(ans, sum + ps[L]);
            ans = max(ans, sum + ps[R]);

            cout << ans << "\n";
        }
    }
}