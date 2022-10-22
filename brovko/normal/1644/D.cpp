#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m, c, q, x[200005], y[200005], k[200005], usedx[200005], usedy[200005], u;

int fx(int i)
{
    if(usedx[i] < u)
        return 0;

    return x[i];
}

int fy(int i)
{
    if(usedy[i] < u)
        return 0;

    return y[i];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m >> c >> q;

        u++;

        set <int> sx, sy;

        for(int i = 0; i < q; i++)
        {
            int r, c;
            cin >> r >> c;

            r--;
            c--;

            x[r] = i + 1;
            usedx[r] = u;

            y[c] = i + 1;
            usedy[c] = u;

            sx.insert(r);
            sy.insert(c);
        }

        int Mx = 1e9, My = 1e9;

        if(sx.size() < n)
            Mx = 0;
        else
        for(int i = 0; i < n; i++)
            Mx = min(Mx, fx(i));

        if(sy.size() < m)
            My = 0;
        else
        for(int j = 0; j < m; j++)
            My = min(My, fy(j));

        for(int i = 0; i <= q; i++)
            k[i] = 0;

        for(auto i:sx)
            if(fx(i) >= max(1, My))
                k[fx(i)]++;

        for(auto i:sy)
            if(fy(i) >= max(1, Mx))
                k[fy(i)]++;

        int cnt = 0;

        for(int i = 0; i <= q; i++)
            cnt += (bool)k[i];

        int ans = 1;

        for(int i = 0; i < cnt; i++)
            ans = ans * 1ll * c % 998244353;

        cout << ans << "\n";
    }
}