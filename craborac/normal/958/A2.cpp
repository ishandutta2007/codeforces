#include <bits/stdc++.h>

using namespace std;

const long long p = 239;
const long long mod = (long long)1e9 + 7;
long long h1[2020], h[220][2020], st[2020];
string s[2020], t[220];

long long modd(long long a)
{
    a %= mod;
    if (a < 0)
        a += mod;
    return a;
}

long long has(int i, int j1, int j2)
{
    return modd(h[i][j2] - h[i][j1] * st[j2 - j1]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        h1[i] = 0;
        for (int j = 0; j < m; j++)
        {
            h1[i] = (h1[i] * p + s[i][j]) % mod;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> t[i];
        h[i][0] = 0;
        for (int j = 0; j < n; j++)
        {
            h[i][j + 1] = (h[i][j] * p + t[i][j]) % mod;
        }
    }
    st[0] = 1;
    for (int i = 0; i < n; i++)
    {
        st[i + 1] = (st[i] * p) % mod;
    }
    for (int i = 0; i + m <= n; i++)
    {
        for (int j = 0; j + m <= n; j++)
        {
            bool d = 1;
            for (int q = 0; q < m; q++)
            {
                if (h1[i + q] != has(q, j, j + m))
                {
                    //cerr << i << " "  << j << " " << q << "    " << h1[i + q] << " " << has(q, j, j + m) << endl;
                    d = 0;
                    break;
                }
            }
            if (d)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
    return 0;
}