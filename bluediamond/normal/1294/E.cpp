#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
int m;
int a[N];

int get(int i, int j)
{
    return a[j + (i - 1) * m];
}


int rep(int val)
{
    val %= n;
    if (val < 0)
    {
        val += n;
    }
    return val;
}

int y()
{
    int sol = 0;
    for (int j = 1; j <= m; j++)
    {
        map<int, int> f;
        map<int, int> mid;
        for (int i = 1; i <= n; i++)
        {
            mid[j + (i - 1) * m] = i - 1;
        }
        for (int i = 1; i <= n; i++)
        {
            int x = get(i, j);
            if (mid.count(x) != 0)
            {
                int id = mid[x];
                int ii = rep(i - id - 1);
                f[ii]++;
            }
        }
        int minc = (int) 1e9;
        for (int i = 0; i < n; i++)
        {
            minc = min(minc, i + n - f[i]);
        }
        sol += minc;
    }
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n * m; i++)
    {
        cin >> a[i];
    }
    cout << y() << "\n";
}