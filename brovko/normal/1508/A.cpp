#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n;
string s[3];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s[0] >> s[1] >> s[2];

        int a = 0, b = 0, c = 0;

        for(int i = 0; i < 2 * n; i++)
        {
            a += s[0][i] - '0';
            b += s[1][i] - '0';
            c += s[2][i] - '0';
        }

        int x = 0, y = 0, d = 0;

        if(a >= n && b >= n)
        {
            x = 0;
            y = 1;
            d = 1;
        }

        if(a >= n && c >= n)
        {
            x = 0;
            y = 2;
            d = 1;
        }

        if(c >= n && b >= n)
        {
            x = 2;
            y = 1;
            d = 1;
        }

        if(a <= n && b <= n)
        {
            x = 0;
            y = 1;
            d = 0;
        }

        if(a <= n && c <= n)
        {
            x = 0;
            y = 2;
            d = 0;
        }

        if(c <= n && b <= n)
        {
            x = 2;
            y = 1;
            d = 0;
        }

        int L = 0, R = 0;

        while(L < 2 * n || R < 2 * n)
        {
            if(L < 2 * n && s[x][L] - '0' != d)
            {
                cout << 1 - d;
                L++;
            }
            else
            if(R < 2 * n && s[y][R] - '0' != d)
            {
                cout << 1 - d;
                R++;
            }
            else
            {
                cout << d;
                L++;
                R++;
            }
        }

        cout << "\n";
    }
}