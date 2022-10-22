#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int MOD = 1e9 + 7;

int n, p, a[200005], F[200005], ps[200005];

int add(int x, int y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

int f(int x)
{
    if(p <= 30 && x >= (1 << p))
        return 0;

    int L = 0;

    while(x)
    {
        x /= 2;
        L++;
    }

    return ps[p - L];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    F[0] = 1;
    F[1] = 1;

    for(int i = 2; i < 200005; i++)
        F[i] = add(F[i - 1], F[i - 2]);

    ps[0] = 1;

    for(int i = 1; i < 200005; i++)
        ps[i] = add(ps[i - 1], F[i]);

    map <int, int> m;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        int x = a[i];
        bool F = m[a[i]];

        while(x > 0 && (x % 4 == 0 || x % 2 != 0))
        {
            if(x % 4 == 0)
                x /= 4;
            else x /= 2;

            F |= m[x];
        }

        if(!F)
            ans = add(ans, f(a[i]));

        m[a[i]] = 1;
    }

    cout << ans;
}