#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100000 + 5;

struct Tower
{
    int a;
    int b;
    ll h;
};

int n;
Tower v[N];

bool cmp (Tower x, Tower y)
{
    return x.b > y.b;
}

int vf = 0;
Tower a[N];

ll dp[N];

struct info
{
    int i;
    int a;
    ll val;
};

bool operator < (info a, info b)
{
    if (a.val == b.val)
    {
        return a.i < b.i;
    }
    else
    {
        return a.val > b.val;
    }
}

int main()
{
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    cout.tie (0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i].a >> v[i].b >> v[i].h;
    }
    sort (v + 1, v + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (i + 1 <= n && v[i + 1].b == v[j].b)
        {
            i++;
        }
        int miA = (1 << 30);
        ll h = 0LL;
        for (int k = j; k <= i; k++)
        {
            miA = min (miA, v[k].a);
            h += v[k].h;
        }
        a[++vf] = {miA, v[j].b, h};
    }
    n = vf;
    for (int i = 1; i <= n; i++)
    {
        v[i] = a[i];
    }
    set<info>s;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = v[i].h;
        while (!s.empty() && s.begin()->a >= v[i].b)
        {
            s.erase (s.begin());
        }
        if (!s.empty() && s.begin()->a < v[i].b)
        {
            dp[i] = max (dp[i], s.begin()->val + v[i].h);
        }
        s.insert ({i, v[i].a, dp[i]});
    }
    ll ans = 0LL;
    for (int i = 1; i <= n; i++)
    {
        ans = max (ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}