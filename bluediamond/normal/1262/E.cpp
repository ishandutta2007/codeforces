#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<vector<int>> a;
vector<vector<int>> sum;
vector<vector<int>> lol;

int get(int r1, int c1, int r2, int c2)
{
    return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

void add(int r1, int c1, int r2, int c2)
{
    lol[r1][c1]++;
    lol[r1][c2 + 1]--;
    lol[r2 + 1][c1]--;
    lol[r2 + 1][c2 + 1]++;
}

void clr()
{
    for (auto &row : lol)
    {
        for (auto &x : row)
        {
            x = 0;
        }
    }
}

bool ok(int l)
{
    clr();
    for (auto &row : lol)
    {
        for (auto &x : row)
        {
            if (x > 1)
            {
                x = 1;
            }
        }
    }
    for (int i = 1; i + l - 1 <= n; i++)
    {
        for (int j = 1; j + l - 1 <= m; j++)
        {
            if (get(i, j, i + l - 1, j + l - 1) == l * l)
            {
                add(i, j, i + l - 1, j + l - 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            lol[i][j] += lol[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            lol[i][j] += lol[i - 1][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (lol[i][j] > 1)
            {
                lol[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (lol[i][j] != a[i][j])
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

 ///   freopen ("input", "r", stdin);

    cin >> n >> m;
    a.resize(n + 2);
    for (int i = 0; i <= n + 1; i++)
    {
        a[i].resize(m + 2, 0);
    }
    sum = a;
    lol = a;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int cur = 0;
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = (s[j - 1] == 'X');
            cur += a[i][j];
            sum[i][j] = sum[i - 1][j] + cur;
        }
    }
    int l = 0, r = max(n, m), ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (ok(2 * mid + 1))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    clr();
    l = 2 * ans + 1;
    for (int i = 1; i + l - 1 <= n; i++)
    {
        for (int j = 1; j + l - 1 <= m; j++)
        {
            if (get(i, j, i + l - 1, j + l - 1) == l * l)
            {
                lol[i + l / 2][j + l / 2] = 1;
            }
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (lol[i][j])
            {
                cout << "X";
            }
            else
            {
                cout << ".";
            }
        }
        cout << "\n";
    }
}