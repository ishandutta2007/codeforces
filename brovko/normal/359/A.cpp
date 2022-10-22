#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int k = 0;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];

            if(a[i][j] == 1)
            {
                k = max(k, 1);

                if(i == 0 || j == 0 || i == n - 1 || j == m - 1)
                    k = max(k, 2);
            }
        }

    if(k >= 2)
        cout << 2;
    else cout << 4;
}