#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, pow10[15];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pow10[0] = 1;

    for(int i = 1; i < 15; i++)
        pow10[i] = pow10[i - 1] * 10;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s;

        int dp = 1988;
        int y = 0;
        int z = 0;

        for(int x = s.size() - 1; x >= 4; x--)
        {
            z += (s[x] - '0') * pow10[y];

            y++;

            if(dp % pow10[y] >= z)
                dp = dp + pow10[y] - dp % pow10[y] + z;
            else dp = dp - dp % pow10[y] + z;
        }

        cout << dp << "\n";
    }
}