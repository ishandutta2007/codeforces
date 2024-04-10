#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[105];

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

        int s = 0;

        for(int i = 0; i < n; i++)
            s += a[i];

        int F = 1;

        for(int i = 2; i * i <= s; i++)
            if(s % i == 0)
                F = 0;

        if(F == 0)
        {
            cout << n << "\n";

            for(int i = 0; i < n; i++)
                cout << i + 1 << ' ';

            cout << "\n";
        }
        else
        {
            cout << n - 1 << "\n";

            for(int i = 0; i < n; i++)
            {
                if(F == 1 && a[i] % 2)
                    F = 0;
                else cout << i + 1 << ' ';
            }

            cout << "\n";
        }
    }
}