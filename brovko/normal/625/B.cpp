#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;

    int n = s.size();
    int m = t.size();
    int ans = 0;

    for(int i = 0; i < n - m + 1; i++)
    {
        if(s.substr(i, m) == t)
        {
            s[i + m - 1] = '#';
            ans++;
        }
    }

    cout << ans;
}