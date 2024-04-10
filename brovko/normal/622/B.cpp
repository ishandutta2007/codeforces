#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

string s;
int a;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> a;

    int x = ((s[0] - '0') * 600 + (s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0' + a) % (24 * 60);

    int h = x / 60;
    int m = x % 60;

    cout << h / 10 << h % 10 << ":" << m / 10 << m % 10;
}