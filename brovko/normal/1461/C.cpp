#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, m, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int x = 0;

        for(int i = 0; i < n; i++)
            if(a[i] != i + 1)
                x = i;

        ld ans = 1;

        for(int i = 0; i < m; i++)
        {
            int r;
            ld p;

            cin >> r >> p;

            if(r > x)
                ans *= 1 - p;
        }

        if(x == 0)
            cout << "1\n";
        else
        cout << setprecision(20) << 1 - ans << "\n";
    }
}