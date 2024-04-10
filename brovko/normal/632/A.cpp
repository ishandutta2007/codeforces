#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, p;
string s[45];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> p;

    for(int i = 0; i < n; i++)
        cin >> s[i];

    int x = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(s[i] == "half")
            x *= 2;
        else x = x * 2 + 1;
    }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        ans += p * x / 2;
        x /= 2;
    }

    cout << ans;
}