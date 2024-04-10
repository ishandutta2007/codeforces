#include <bits/stdc++.h>
#define int long long
#define ld long double

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

        int a[n];

        int Max = n - 1;

        for(int i = 0; i < n - 1; i += 2)
        {
            cout << "? " << 1 << ' ' << i + 1 << ' ' << i + 2 << ' ' << n - 1 << endl;

            int x;
            cin >> x;

            if(x == n)
                Max = i + 1;

            if(x == n - 1)
            {
                cout << "? " << 1 << ' ' << i + 2 << ' ' << i + 1 << ' ' << n - 1 << endl;

                cin >> x;

                if(x == n)
                    Max = i;
            }
        }

        a[Max] = n;

        for(int i = 0; i < n; i++)
            if(i != Max)
        {
            cout << "? " << 2 << ' ' << i + 1 << ' ' << Max + 1 << ' ' << 1 << endl;

            int x;
            cin >> x;

            a[i] = x;
        }

        cout << "! ";

        for(int i = 0; i < n; i++)
            cout << a[i] << ' ';

        cout << endl;
    }
}