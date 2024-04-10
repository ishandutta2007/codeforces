#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500 + 7;
int n;
int m;
int a[N][N];
int b[N][N];

int sa(int r1, int c1, int r2, int c2)
{
    return a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1];
}

int sb(int r1, int c1, int r2, int c2)
{
    return b[r2][c2] - b[r1 - 1][c2] - b[r2][c1 - 1] + b[r1 - 1][c1 - 1];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = (s[j - 1] == '.');
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            b[i][j] = (a[i][j] && a[i][j + 1]);
            a[i][j] = (a[i][j] && a[i + 1][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ca = 0, cb = 0;
        for (int j = 1; j <= m; j++)
        {
            ca += a[i][j];
            cb += b[i][j];
            a[i][j] = ca + a[i - 1][j];
            b[i][j] = cb + b[i - 1][j];
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout << sb(r1, c1, r2, c2 - 1) + sa(r1, c1, r2 - 1, c2) << "\n";
    }
}