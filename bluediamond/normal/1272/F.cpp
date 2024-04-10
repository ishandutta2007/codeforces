#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 200 + 7;
const int INF = (int) 1e9;

int n;
int m;
string ss;
string t;

struct kek
{
    int a;
    int b;
    int c;
};

int mn[2 * N][N][N];
kek par[2 * N][N][N];
int a[N];
int b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> ss >> t;
    n = (int) ss.size();
    m = (int) t.size();
    for (int i = 1; i <= n; i++)
    {
        if (ss[i - 1] == '(')
        {
            a[i] = +1;
        }
        else
        {
            a[i] = -1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (t[i - 1] == '(')
        {
            b[i] = +1;
        }
        else
        {
            b[i] = -1;
        }
    }
    for (int i = 0; i < 2 * N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                mn[i][j][k] = INF;
            }
        }
    }
    mn[0][0][0] = 1;
    for (int x = 0; x <= n; x++)
    {
        for (int y = 0; y <= m; y++)
        {
            for (int top = 0; top < 2 * N; top++)
            {
                if (mn[top][x][y] == INF)
                {
                    continue;
                }
                for (int s = -1; s <= +1; s += 2)
                {
                    int tn = top + s;
                    if (0 <= tn && tn < 2 * N)
                    {
                        int xn = x;
                        int yn = y;
                        if (x < n && a[x + 1] == s)
                        {
                            xn++;
                        }
                        if (y < m && b[y + 1] == s)
                        {
                            yn++;
                        }
                      ///  cout << xn << " " << yn << "\n";
                    //    cout << top << " " << x << " " << y << " : " << tn << " " << xn << " " << yn << "\n";
                        mn[tn][xn][yn] = min(mn[tn][xn][yn], mn[top][x][y] + 1);
                        if (mn[tn][xn][yn] == mn[top][x][y] + 1)
                        {
                            par[tn][xn][yn] = {top, x, y};
                        }
                    }
                }
            ///    return 0;
            }
            for (int top = 2 * N - 1; top >= 0; top--)
            {
                if (mn[top][x][y] == INF)
                {
                    continue;
                }
                for (int s = -1; s <= +1; s += 2)
                {
                    int tn = top + s;
                    if (0 <= tn && tn < 2 * N)
                    {
                        int xn = x;
                        int yn = y;
                        if (x < n && a[x + 1] == s)
                        {
                            xn++;
                        }
                        if (y < m && b[y + 1] == s)
                        {
                            yn++;
                        }
                      ///  cout << xn << " " << yn << "\n";
                    //    cout << top << " " << x << " " << y << " : " << tn << " " << xn << " " << yn << "\n";
                        mn[tn][xn][yn] = min(mn[tn][xn][yn], mn[top][x][y] + 1);
                        if (mn[tn][xn][yn] == mn[top][x][y] + 1)
                        {
                            par[tn][xn][yn] = {top, x, y};
                        }
                    }
                }
            ///    return 0;
            }
        }
    }
    vector<int> vals;
    int a = 0;
    int b = n;
    int c = m;
    for (int i = 1; i < mn[0][n][m]; i++)
    {
        int an = par[a][b][c].a;
        int bn = par[a][b][c].b;
        int cn = par[a][b][c].c;
        if (a - an == 1)
        {
            vals.push_back(1);
        }
        else
        {
            vals.push_back(-1);
        }
        a = an;
        b = bn;
        c = cn;
    }
    reverse(vals.begin(), vals.end());
    for (auto &x : vals)
    {
        if (x == +1)
        {
            cout << "(";
        }
        else
        {
            cout << ")";
        }
    }
    cout << "\n";
}