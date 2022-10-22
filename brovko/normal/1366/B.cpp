#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, m, x, L, R, l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> x >> m;

        L = x;
        R = x;

        for(int i = 0; i < m; i++)
        {
            cin >> l >> r;

            if(min(R, r) >= max(L, l))
            {
                L = min(L, l);
                R = max(R, r);
            }
        }

        cout << R - L + 1 << "\n";
    }
}