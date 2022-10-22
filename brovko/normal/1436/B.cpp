#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, a[105][105];

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
            for(int j = 0; j < n; j++)
                a[i][j] = 0;

        for(int i = 0; i < n; i += 2)
        {
            a[i][i] = 1;
            a[i][i + 1] = 1;
            a[i + 1][i] = 1;
            a[i + 1][i + 1] = 1;
        }

        if(n % 2)
        {
            for(int i = n - 3; i < n; i++)
                for(int j = n - 3; j < n; j++)
                    a[i][j] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << a[i][j] << ' ';

            cout << "\n";
        }
    }
}