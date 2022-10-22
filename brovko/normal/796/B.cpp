#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, h, used[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < m; i++)
    {
        cin >> h;
        used[h] = 1;
    }

    int x = 1;

    while(k--)
    {
        int u, v;
        cin >> u >> v;

        if(v == x)
            swap(u, v);

        if(u == x && used[u] == 0)
            x = v;
    }

    cout << x;
}