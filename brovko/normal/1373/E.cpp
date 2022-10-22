#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, k;

int f(int x)
{
    int ans = 0;

    while(x)
    {
        ans += x % 10;
        x /= 10;
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        int ans = -1;

        for(int i = 0; i <= 10000; i++)
        {
            int p = 0;

            for(int j = i; j <= i + k; j++)
                p += f(j);

            if(p == n && ans == -1)
                ans = i;
        }

        int X = -1;
        int C = -1;
        int Y = -1;
        int Z = -1;

        for(int c = 0; c <= n; c++)
            for(int x = 1; x < 10; x++)
                {
                    int y = 8;

                    for(int z = 0; z < 10; z++)
                        {
                            int s = 0;

                            for(int i = z; i <= z + k; i++)
                                s += y + i % 10 + i / 10 + x + c * 9;

                            if(s == n && X == -1)
                            {
                                X = x;
                                Y = y;
                                C = c;
                                Z = z;
                            }
                        }

                    y = 9;

                    for(int z = 0; z <= 9 - k; z++)
                    {
                        int s = 0;

                            for(int i = z; i <= z + k; i++)
                                s += y + i % 10 + i / 10 + x + c * 9;

                            if(s == n && X == -1)
                            {
                                X = x;
                                Y = y;
                                C = c;
                                Z = z;
                            }
                    }
                }

        if(ans != -1)
            cout << ans;
        else if(X != -1)
        {
            cout << X;
            for(int i = 0; i < C; i++)
                cout << 9;

            cout << Y << Z;
        }
        else cout << -1;

        cout << "\n";
    }
}