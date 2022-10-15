#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000 + 7;
int t;
int n;
int a[N];
int f[N][30];

int get(int l, int r, int x)
{
    return f[r][x] - f[l - 1][x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int x = 1; x <= 26; x++)
            {
                f[i][x] = 0;
            }
            f[i][a[i]]++;
            for (int x = 1; x <= 26; x++)
            {
                f[i][x] += f[i - 1][x];
            }
        }
        int sol = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] == a[j])
                {
                    int mf = 0;
                    for (int x = 1; x <= 26; x++)
                    {
                        mf = max(mf, get(i + 1, j - 1, x));
                    }
                    sol = max(sol, mf + 2 * min(get(1, i, a[i]), get(j, n, a[i])));
                }
            }
        }
        cout << sol << "\n";
    }
}