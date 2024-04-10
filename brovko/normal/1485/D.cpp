#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, m, a[505][505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if((i + j) % 2 == 0)
                cout << 720720 << ' ';
            else cout << 720720 - a[i][j] * a[i][j] * a[i][j] * a[i][j] << ' ';
        }

        cout << "\n";
    }
}