#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int a, ta, b, tb;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> ta >> b >> tb >> s;

    int x = (s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';

    int l = max(x - tb, 299ll);
    int r = min(x + ta, 24ll * 60);

    l -= 300 - b;
    r -= 301 - b;

    l -= l % b;

    cout << (r - l) / b;
}