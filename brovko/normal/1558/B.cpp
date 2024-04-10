#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int n, m, lp[4000005], dp[4000005], s, p;
vector <pair <int, int> > v;

int add(int x, int y)
{
    return (x + y) % m;
}

int sub(int x, int y)
{
    return add(x, m - y);
}

void rec(int i, int x, int d)
{
    //cout << x << endl;

    if(d >= v.size())
    {
        if(x > 1)
            p = add(p, sub(dp[i / x], dp[i / x - 1]));

        return;
    }

    for(int j = 0; j <= v[d].y; j++)
    {
        if(j > 0)
            x *= v[d].x;

        rec(i, x, d + 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 2; i * i < 4000005; i++)
        if(lp[i] == 0)
            for(int j = i * i; j < 4000005; j += i)
                if(lp[j] == 0)
                    lp[j] = i;

    for(int i = 1; i < 4000005; i++)
        if(lp[i] == 0)
            lp[i] = i;

    dp[1] = 1;
    s = 1;

    for(int i = 2; i <= n; i++)
    {
        int x = i;

        v.clear();

        while(x > 1)
        {
            int y = lp[x], z = 0;

            while(lp[x] == y)
            {
                z++;
                x /= y;
            }

            v.pb({y, z});
        }

        rec(i, 1, 0);

        dp[i] = add(s, p);
        s = add(s, dp[i]);
    }

    cout << dp[n];
}