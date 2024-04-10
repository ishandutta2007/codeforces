#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, s, t, c[200005], v[200005], g[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> s >> t;

    for(int i = 0; i < n; i++)
        cin >> c[i] >> v[i];

    for(int i = 0; i < k; i++)
        cin >> g[i];

    sort(g, g + k);
    g[k] = s;

    int L = -1;
    int R = 2e9 + 7;

    while(R - L > 1)
    {
        int M = (L + R) / 2;
        int T = 0;

        for(int i = -1; i < k; i++)
        {
            int x;

            if(i != -1)
                x = g[i + 1] - g[i];
            else x = g[0];

            int y = max(0ll, 2 * x - M);

            if(y > x)
                T = 2e9 + 7;
            else T += x + y;
        }

        if(T <= t)
            R = M;
        else L = M;
    }

    int Min = 2e9 + 7;

    for(int i = 0; i < n; i++)
    {
        if(v[i] >= R)
            Min = min(Min, c[i]);
    }

    if(Min == 2e9 + 7)
        cout << -1;
    else cout << Min;
}