#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int g = 0;

        for(int j = 0; j < 30; j++)
        {
            int k = 0;

            for(int i = 0; i < n; i++)
                if(a[i] & (1ll << j))
                    k++;

            g = __gcd(g, k);
        }

        if(g == 0)
        {
            for(int i = 1; i <= n; i++)
                cout << i << ' ';

            cout << "\n";
        }
        else
        {
            for(int i = 1; i <= g; i++)
                if(g % i == 0)
                    cout << i << ' ';

            cout << "\n";
        }
    }
}