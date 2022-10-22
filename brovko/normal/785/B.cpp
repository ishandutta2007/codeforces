#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, l, r, Ml1, Mr1, Ml2, Mr2;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    Ml1 = -1e18;
    Ml2 = -1e18;

    Mr1 = 1e18;
    Mr2 = 1e18;

    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;

        Ml1 = max(Ml1, l);
        Mr1 = min(Mr1, r);
    }

    cin >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> l >> r;

        Ml2 = max(Ml2, l);
        Mr2 = min(Mr2, r);
    }

    cout << max(0ll, max(Ml2 - Mr1, Ml1 - Mr2));
}