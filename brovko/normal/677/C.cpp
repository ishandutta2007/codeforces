#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;
const int MOD = 1e9 + 7;

string s;
int a[65];

int f(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';

    if(c >= 'A' && c <= 'Z')
        return c - 'A' + 10;

    if(c >= 'a' && c <= 'z')
        return c - 'a' + 36;

    if(c == '-')
        return 62;

    if(c == '_')
        return 63;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 64; i++)
    {
        for(int j = 0; j < 64; j++)
            for(int k = 0; k < 64; k++)
                if((j & k) == i)
                    a[i]++;
    }

    cin >> s;

    int ans = 1;

    for(auto to:s)
    {
        ans = ans * a[f(to)] % MOD;
    }

    cout << ans;
}