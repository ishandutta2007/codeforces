#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> m, d;

        for(int i = 0; i < 2 * n; i++)
        {
            int x, y;
            cin >> x >> y;

            if(x == 0)
                m.push_back(abs(y));
            else d.push_back(abs(x));
        }

        sort(m.begin(), m.end());
        sort(d.begin(), d.end());

        ld ans = 0;

        for(int i = 0; i < n; i++)
            ans += sqrt((ld)m[i] * m[i] + d[i] * d[i]);

        cout << setprecision(20) << ans << "\n";
    }
}