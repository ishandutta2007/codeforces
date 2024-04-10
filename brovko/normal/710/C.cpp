#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n / 2; i++)
        for(int j = 0; i + j < n / 2; j++)
    {
        a[i][j] = 1;
        a[n - 1 - i][j] = 1;

        a[i][n - 1 - j] = 1;
        a[n - i - 1][n - 1 - j] = 1;
    }

    int c = 2, nc = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
    {
        if(a[i][j])
        {
            a[i][j] = c;
            c += 2;
        }

        else
        {
            a[i][j] = nc;
            nc += 2;
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << ' ';

        cout << "\n";
    }
}