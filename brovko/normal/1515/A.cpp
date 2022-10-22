#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;

int t, n, x, a[105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        int s = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        if(s == x)
            cout << "NO\n";
        else
        {
            cout << "YES\n";

            for(int i = 0; i < n; i++)
            {
                if(x == a[i])
                {
                    x -= a[i] + a[i + 1];
                    cout << a[i + 1] << ' ' << a[i] << ' ';
                    i++;
                }
                else
                {
                    x -= a[i];
                    cout << a[i] << ' ';
                }
            }

            cout << "\n";
        }
    }
}