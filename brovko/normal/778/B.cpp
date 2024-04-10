#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[5005][1005], k[1005];
map <string, int> M;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int j = 0; j < 1005; j++)
        a[5004][j] = 2;

    M["?"] = 5004;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string b, c, d;
        cin >> b >> c >> d;

        M[b] = i;

        if(d[0] == '0' || d[0] == '1')
        {
            for(int j = 0; j < m; j++)
                a[i][j] = d[j] - '0';
        }
        else
        {
            string e, x;
            cin >> e >> x;

            int y = M[d];
            int z = M[x];

                for(int j = 0; j < m; j++)
                {
                    if(e == "AND")
                        {
                            if(a[y][j] == 0 || a[z][j] == 0)
                                a[i][j] = 0;

                            else if(a[y][j] == 1 && a[z][j] == 1)
                                a[i][j] = 1;

                            else if(a[y][j] == a[z][j])
                                a[i][j] = a[y][j];

                            else if(a[y][j] == -1 && a[z][j] == 2 || a[y][j] == 2 && a[z][j] == -1)
                                a[i][j] = 0;

                            else a[i][j] = a[y][j] + a[z][j] - 1;
                        }
                    else if(e == "OR")
                        {
                            if(a[y][j] == 1 || a[z][j] == 1)
                                a[i][j] = 1;

                            else if(a[y][j] == 0 && a[z][j] == 0)
                                a[i][j] = 0;

                            else if(a[y][j] == a[z][j])
                                a[i][j] = a[y][j];

                            else if(a[y][j] == -1 && a[z][j] == 2 || a[y][j] == 2 && a[z][j] == -1)
                                a[i][j] = 1;

                            else a[i][j] = a[y][j] + a[z][j];
                        }
                    else
                        {
                            if(a[y][j] == 0)
                                a[i][j] = a[z][j];

                            else if(a[y][j] == 1)
                                a[i][j] = 1 - a[z][j];

                            else if(a[y][j] == 2)
                            {
                                if(a[z][j] == 0)
                                    a[i][j] = 2;

                                else if(a[z][j] == 1)
                                    a[i][j] = -1;

                                else if(a[z][j] == 2)
                                    a[i][j] = 0;

                                else a[i][j] = 1;
                            }

                            else
                            {
                                if(a[z][j] == 0)
                                    a[i][j] = -1;

                                else if(a[z][j] == 1)
                                    a[i][j] = 2;

                                else if(a[z][j] == 2)
                                    a[i][j] = 1;

                                else a[i][j] = 0;
                            }
                        }
                }
        }

        /*for(int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;*/
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(a[i][j] == 2)
            k[j]++;
        else if(a[i][j] == -1)
            k[j]--;
    }

    for(int i = 0; i < m; i++)
    {
        if(k[i] < 0)
            cout << 1;
        else cout << 0;
    }

    cout << "\n";

    for(int i = 0; i < m; i++)
    {
        if(k[i] > 0)
            cout << 1;
        else cout << 0;
    }
}