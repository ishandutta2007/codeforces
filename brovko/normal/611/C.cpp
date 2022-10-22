#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, psu[505][505], psl[505][505];
char a[505][505];

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
        for(int j = 0; j < m; j++)
        {
            int x = 0;

            if(i > 0 && a[i][j] == '.' && a[i - 1][j] == '.')
                x = 1;

            int y = 0;

            if(j > 0 && a[i][j] == '.' && a[i][j - 1] == '.')
                y = 1;

            psu[i + 1][j + 1] = psu[i + 1][j] + psu[i][j + 1] - psu[i][j] + x;
            psl[i + 1][j + 1] = psl[i + 1][j] + psl[i][j + 1] - psl[i][j] + y;
        }

    int q;
    cin >> q;

    while(q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        cout << psu[r2][c2] + psu[r1][c1 - 1] - psu[r2][c1 - 1] - psu[r1][c2] + psl[r2][c2] + psl[r1 - 1][c1] - psl[r2][c1] - psl[r1 - 1][c2] << "\n";
    }
}