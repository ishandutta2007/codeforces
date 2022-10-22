#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, t, tp, tu, td, a[305][305], l[305][305], r[305][305], u[305][305], d[305][305];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> t >> tp >> tu >> td;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == a[i - 1][j])
            {
                u[i - 1][j] = tp;
                d[i][j] = tp;
            }
            else if(a[i][j] < a[i - 1][j])
            {
                u[i - 1][j] = tu;
                d[i][j] = td;
            }
            else
            {
                u[i - 1][j] = td;
                d[i][j] = tu;
            }
        }

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
        {
            if(a[i][j] == a[i][j - 1])
            {
                l[i][j - 1] = tp;
                r[i][j] = tp;
            }
            else if(a[i][j] < a[i][j - 1])
            {
                l[i][j - 1] = tu;
                r[i][j] = td;
            }
            else
            {
                l[i][j - 1] = td;
                r[i][j] = tu;
            }
        }

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            r[i][j] += r[i][j - 1];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] += d[i - 1][j];

    for(int i = 0; i < n; i++)
        for(int j = m - 2; j >= 0; j--)
            l[i][j] += l[i][j + 1];

    for(int i = n - 2; i >= 0; i--)
        for(int j = 0; j < m; j++)
            u[i][j] += u[i + 1][j];

    int ans = 1e9;
    int A = 0, B = 0, C = 0, D = 0;

    for(int i = 0; i < n; i++)
        for(int j = i + 2; j < n; j++)
        {
            set <pair <int, int> > q;
            q.insert({d[j][m - 1] - d[i][m - 1], m - 1});

            for(int k = m - 3; k >= 0; k--)
            {
                int s = u[i][k] - u[j][k] + l[j][k] + r[i][m - 1] - r[i][k];

                auto it = q.lower_bound({t - s, (int)-1e9});

                if(it != q.end())
                {
                    pair <int, int> p = (*it);

                    if(abs(t - s - p.x) < ans)
                    {
                        ans = abs(t - s - p.x);
                        A = i + 1;
                        B = k + 1;
                        C = j + 1;
                        D = p.y + 1;
                    }
                }

                if(it != q.begin())
                {
                    it--;

                    pair <int, int> p = (*it);

                    if(abs(t - s - p.x) < ans)
                    {
                        ans = abs(t - s - p.x);
                        A = i + 1;
                        B = k + 1;
                        C = j + 1;
                        D = p.y + 1;
                    }
                }

                q.insert({r[i][k + 1] - r[i][m - 1] - l[j][k + 1] + d[j][k + 1] - d[i][k + 1], k + 1});
            }
        }
        
    cout << A << ' ' << B << ' ' << C << ' ' << D;
}