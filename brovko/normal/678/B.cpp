#include <bits/stdc++.h>
#define int long long
#define ld double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int y;

int vis(int x)
{
    return (x % 4 == 0 && (x % 100 != 0 || x % 400 == 0));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> y;
    int x = 0;

    for(int i = y + 1; i < 1e9; i++)
    {
        if(vis(i - 1))
            x = (x + 366) % 7;

        else x = (x + 365) % 7;

        if(x == 0 && vis(i) == vis(y))
        {
            cout << i;
            return 0;
        }
    }
}