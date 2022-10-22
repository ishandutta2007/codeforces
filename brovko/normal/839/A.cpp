#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, s, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(int i = 0; i < n; i++)
    {
        s += a[i];
        k -= min(s, 8ll);

        s -= min(s, 8ll);

        if(k <= 0)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;
}