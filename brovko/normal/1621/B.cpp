#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        int Min = 1e18, Max = 1e18, Minmax = 1e18, L = 1e18, R = -1e18;

        for(int i = 0; i < n; i++)
        {
            int l, r, c;
            cin >> l >> r >> c;

            if(l < L)
            {
                L = l;
                Min = 1e18;
                Minmax = 1e18;
            }

            if(r > R)
            {
                R = r;
                Max = 1e18;
                Minmax = 1e18;
            }

            if(l == L)
                Min = min(Min, c);

            if(r == R)
                Max = min(Max, c);

            if(l == L && r == R)
                Minmax = min(Minmax, c);

            cout << min(Min + Max, Minmax) << "\n";
        }
    }
}