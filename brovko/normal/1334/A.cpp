#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, p[105], c[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int w = 0, l = 0, f = 1;

        for(int i = 0; i < n; i++)
        {
            cin >> p[i] >> c[i];

            if(c[i] >= w && p[i] - c[i] >= l)
            {
                w = c[i];
                l = p[i] - c[i];
            }
            else f = 0;
        }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}