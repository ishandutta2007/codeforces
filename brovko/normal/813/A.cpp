#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[1005], l[1005], r[1005], s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> l[i] >> r[i];
        if(s <= r[i])
        {
            cout << max(l[i], s);
            return 0;
        }
    }

    cout << -1;
}