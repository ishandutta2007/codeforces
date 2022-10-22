#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    int ans = 0;

    for(auto to:s)
        if((to - '0') % 4 == 0)
            ans++;

    for(int i = 0; i < n - 1; i++)
    {
        if((s[i] * 10 + s[i + 1] - '0' * 11) % 4 == 0)
            ans += i + 1;
    }

    cout << ans;
}