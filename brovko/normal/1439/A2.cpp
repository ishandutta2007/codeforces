#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, m;
char a[505][505];
vector <int> v;

void f(int x, int y)
{
    a[x][y] = '0' + '1' - a[x][y];

    v.pb(x + 1);
    v.pb(y + 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        v.clear();

        if(n % 2 != 0)
        {
            for(int j = 0; j < m - 1; j++)
            {
                if(a[n - 1][j] == '1')
                {
                    f(n - 1, j);
                    f(n - 2, j);
                    f(n - 2, j + 1);
                }
            }

            if(a[n - 1][m - 1] == '1')
            {
                f(n - 1, m - 1);
                f(n - 2, m - 1);
                f(n - 2, m - 2);
            }

            n--;
        }

        if(m % 2 != 0)
        {
            for(int i = 0; i < n - 1; i++)
            {
                if(a[i][m - 1] == '1')
                {
                    f(i, m - 1);
                    f(i, m - 2);
                    f(i + 1, m - 2);
                }
            }

            if(a[n - 1][m - 1] == '1')
            {
                f(n - 1, m - 1);
                f(n - 1, m - 2);
                f(n - 2, m - 2);
            }

            m--;
        }

        for(int i = 0; i < n; i += 2)
            for(int j = 0; j < m; j += 2)
                while((int)a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j + 1] != 4 * (int)'0')
                {
                    int x = a[i][j] * 8 + a[i + 1][j] * 4 + a[i][j + 1] * 2 + a[i + 1][j + 1] - 15 * '0';

                    if(x == 1 || x == 7)
                    {
                        f(i + 1, j);
                        f(i, j + 1);
                        f(i + 1, j + 1);
                    }
                    else

                    if(x == 2 || x == 11)
                    {
                        f(i, j);
                        f(i, j + 1);
                        f(i + 1, j + 1);
                    }
                    else

                    if(x == 6 || x == 10 || x == 13)
                    {
                        f(i, j);
                        f(i + 1, j);
                        f(i + 1, j + 1);
                    }

                    else
                    {
                        f(i, j);
                        f(i + 1, j);
                        f(i, j + 1);
                    }
                }

        cout << v.size() / 6 << "\n";

        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';

            if(i % 6 == 5)
                cout << "\n";
        }
    }
}