#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int L, R, m;
vector <pair <int, int> > g[40];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> R;
    int N = R - L + 1;

    int n = 2;

    while(N > (1ll << n - 2))
        n++;

    int x = 1;

    for(int i = n; i >= 3; i--)
    {
        for(auto to:g[1])
        {
            g[i].push_back(to);
            m++;
        }

        g[1].push_back({i, x});
        m++;

        if(i < n)
        x *= 2;
    }

    if(N == 2 * x)
    {
        for(auto to:g[1])
        {
            g[2].push_back(to);
            m++;
        }

        g[1].push_back({2, x});
        m++;
        x *= 2;
    }
    else
    {
        g[1].push_back({2, 1});
        m++;
        int d = N - x;

        for(int i = 0; i <= 30; i++)
        {
            int y = (1ll << i);

            if(d & y)
            {
                g[2].push_back({n - 1 - i, x - 1});
                m++;
                x += y;
            }
        }
    }

    if(L > 1)
    {
        n++;
        g[n - 1].push_back({n, L - 1});
        m++;
    }

    cout << "YES\n" << n << ' ' << m << "\n";

    for(int i = 1; i <= n; i++)
        for(auto to:g[i])
            cout << i << ' ' << to.first << ' ' << to.second << "\n";
}