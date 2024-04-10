#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[27][27];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
    {
        if(i % 2 == 0)
            a[i][j] = 0;
        else a[i][j] = (1ll << i + j - 1);
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << a[i][j] << ' ';

        cout << endl;
    }

    int q;
    cin >> q;

    while(q--)
    {
        int k;
        cin >> k;

        int x = 0, y = 0;

        cout << "1 1" << endl;

        while(x < n - 1 || y < n - 1)
        {
            if(k % 2 == 0)
            {
                if(x % 2 == 0)
                    y++;
                else x++;
            }
            else
            {
                if(x % 2 == 0)
                    x++;
                else y++;
            }

            cout << x + 1 << ' ' << y + 1 << endl;

            k /= 2;
        }
    }
}