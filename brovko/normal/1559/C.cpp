#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005];

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

        if(a[0] == 1)
        {
            cout << n + 1 << ' ';

            for(int i = 0; i < n; i++)
                cout << i + 1 << ' ';

            cout << "\n";
        }

        else
        if(a[n - 1] == 0)
        {
            for(int i = 0; i <= n; i++)
                cout << i + 1 << ' ';

            cout << "\n";
        }

        else
        {
            int f = 0;

            for(int i = 0; i < n; i++)
            {
                cout << i + 1 << ' ';

                if(a[i] == 0 && a[i + 1] == 1 && f == 0)
                {
                    f = 1;
                    cout << n + 1 << ' ';
                }
            }

            cout << "\n";
        }
    }
}