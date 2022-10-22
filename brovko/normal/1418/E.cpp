#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;
const int MOD = 998244353;

int n, m, d[200005], a[200005], b[200005], ans[200005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return (x % MOD) * (y % MOD) % MOD;
}

int binpow(int x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    int z = binpow(x, y / 2);

    return mul(z, z);
}

int inv(int x)
{
    return binpow(x, MOD - 2);
}

int divide(int x, int y)
{
    return mul(x, inv(y));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> d[i];

    for(int i = 0; i < m; i++)
        cin >> a[i] >> b[i];

    vector <pair <int, int> > v;

    for(int i = 0; i < m; i++)
        v.pb({b[i], i});

    sort(v.begin(), v.end());

    int S = 0;

    sort(d, d + n);

    for(int i = 0; i < n; i++)
        S += d[i];

    int s = 0, x = 0;

    for(int i = 0; i < n; i++)
    {
        while(x < m && d[i] >= v[x].x)
        {
            int j = v[x].y;
            int k = n - i;

//            cout << i << ' ' << j << endl;

            ans[j] = add(mul(S - s, divide(max(0ll, k - a[j]), k)), mul(s, divide(max(0ll, k - a[j] + 1), k + 1)));
            x++;
        }

        s += d[i];
    }

    for(int i = 0; i < m; i++)
        cout << ans[i] << "\n";
}