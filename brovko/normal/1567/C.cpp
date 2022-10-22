#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;
        int ans = 0;

        for(int mask = 0; mask < 1024; mask += 4)
        {
            int x = 1;

            int m = n, z = 0;

            for(int i = 0; i < 15; i++)
            {
                int y = m % 10;

                if(mask & (1ll << z))
                    y--;

                if(mask & (1ll << z + 2))
                    y += 10;

                x *= max(0ll, min(y + 1, 19 - y));

                m /= 10;
                z++;
            }

//            if(x > 0)
//                cout << mask << ' ' << x << endl;

            ans += x;
        }

        cout << ans - 2 << "\n";
    }
}