#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m;
char a[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        cin >> a[i][j];
    }

    if(n % 3 == 0)
    {
        int f = 1;
        int p = n / 3;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
        {
            if(a[i][j] != a[i / p * p][0])
                f = 0;
        }

        int x = a[0][0];
        int y = a[n / 3][0];
        int z = a[n / 3 * 2][0];

        if(x == y || y == z || x == z)
            f = 0;

        if(f)
        {
            cout << "YES";
            return 0;
        }
    }

    if(m % 3 == 0)
    {
        int f = 1;
        int p = m / 3;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
        {
            if(a[i][j] != a[0][j / p * p])
                f = 0;
        }

        int x = a[0][0];
        int y = a[0][m / 3];
        int z = a[0][m / 3 * 2];

        if(x == y || y == z || x == z)
            f = 0;

        if(f)
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}