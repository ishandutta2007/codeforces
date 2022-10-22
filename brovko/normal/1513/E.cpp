#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
const int MOD = 1e9 + 7;

int n, a[100005], fact[100005];

int add(int x, int y)
{
    return (x + y) % MOD;
}

int mul(int x, int y)
{
    return x * y % MOD;
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

int C(int x, int y)
{
    return divide(fact[x], mul(fact[x - y], fact[y]));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;

    for(int i = 1; i < 100005; i++)
        fact[i] = mul(i, fact[i - 1]);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int s = 0;

    for(int i = 0; i < n; i++)
        s += a[i];

    if(s % n)
    {
        cout << 0;
        return 0;
    }

    int x = s / n;

    int kp = 0, km = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] > x)
            kp++;

        if(a[i] < x)
            km++;
    }

    if(km > 1 && kp > 1)
    {
        int kz = n - kp - km;

        vector <int> v;

        for(int i = 0; i < n; i++)
            if(a[i] > x)
                v.push_back(a[i]);

        sort(v.begin(), v.end());

        int m = v.size();

        int k = 0, ans = fact[m];

        for(int i = 0; i < m; i++)
        {
            if(i == 0 || v[i] == v[i - 1])
                k++;

            if(i == m - 1 || i > 0 && v[i] != v[i - 1])
            {
                ans = divide(ans, fact[k]);
                k = 1;
            }
        }

        int p = ans;



        v.clear();

        for(int i = 0; i < n; i++)
            if(a[i] < x)
                v.push_back(a[i]);

        sort(v.begin(), v.end());

        m = v.size();

        k = 0, ans = fact[m];

        for(int i = 0; i < m; i++)
        {
            if(i == 0 || v[i] == v[i - 1])
                k++;

            if(i == m - 1 || i > 0 && v[i] != v[i - 1])
            {
                ans = divide(ans, fact[k]);
                k = 1;
            }
        }

        p = mul(p, ans);

        cout << mul(p, mul(2, C(n, kz)));

        return 0;
    }

    sort(a, a + n);

    int k = 0, ans = fact[n];

    for(int i = 0; i < n; i++)
    {
        if(i == 0 || a[i] == a[i - 1])
            k++;

        if(i == n - 1 || i > 0 && a[i] != a[i - 1])
        {
            ans = divide(ans, fact[k]);
            k = 1;
        }
    }

    cout << ans;
}