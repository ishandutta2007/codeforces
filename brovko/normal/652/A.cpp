#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int h1, h2, a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h1 >> h2 >> a >> b;

    h1 += a * 8;

    for(int i = 0; i < 1000000; i++)
    {
        if(h1 >= h2)
        {
            cout << i;
            return 0;
        }

        h1 += (a - b) * 12;
    }

    cout << -1;
}