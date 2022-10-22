#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m;
char a[1005][1005];

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
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        if(n == 2)
        {
            if(m % 2 == 0 &&  a[0][1] != a[1][0])
                cout << "NO\n";
            else
            {
                cout << "YES\n";

                for(int i = 0; i <= m; i++)
                    cout << i % 2 + 1 << ' ';

                cout << "\n";
            }
        }
        else
        {
            cout << "YES\n";

            if(m % 2)
            {
                for(int i = 0; i <= m; i++)
                    cout << i % 2 + 1 << ' ';

                cout << "\n";
            }
            else
            {
                int x = -1, y = -1;

                for(int i = 0; i < n; i++)
                    for(int j = 0; j < i; j++)
                        if(a[i][j] == a[j][i])
                        {
                            x = i;
                            y = j;
                        }

                if(x != -1)
                {
                    for(int i = 0; i <= m; i++)
                    {
                        if(i % 2 == 0)
                            cout << x + 1 << ' ';
                        else cout << y + 1 << ' ';
                    }

                    cout << "\n";
                }
                else
                {
                    int z = -1, Ra = -1, Rb = -1;

                    for(int i = 0; i < n; i++)
                    {
                        int ra = -1, rb = -1;

                        for(int j = 0; j < n; j++)
                        {
                            if(a[i][j] == 'a')
                                ra = j;

                            if(a[i][j] == 'b')
                                rb = j;
                        }

                        if(ra > -1 && rb > -1)
                        {
                            z = i;
                            Ra = ra;
                            Rb = rb;
                        }
                    }

                    if(m % 4 == 0)
                    {
                        for(int i = 0; i <= m; i++)
                        {
                            if(i % 2 == 0)
                                cout << z + 1 << ' ';

                            if(i % 4 == 1)
                                cout << Ra + 1 << ' ';

                            if(i % 4 == 3)
                                cout << Rb + 1 << ' ';
                        }

                        cout << "\n";
                    }
                    else
                    {
                        m -= 2;
                        cout << Rb + 1 << ' ';

                        for(int i = 0; i <= m; i++)
                        {
                            if(i % 2 == 0)
                                cout << z + 1 << ' ';

                            if(i % 4 == 1)
                                cout << Ra + 1 << ' ';

                            if(i % 4 == 3)
                                cout << Rb + 1 << ' ';
                        }

                        cout << Ra + 1 << "\n";
                    }
                }
            }
        }
    }
}