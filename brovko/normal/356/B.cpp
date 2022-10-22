#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    li n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    int x = s.size(), y = t.size();

    int g = __gcd(x, y);

    int k[g][26];

    for(int i = 0; i < g; i++)
        for(int j = 0; j < 26; j++)
            k[i][j] = 0;

    for(int i = 0; i < x; i++)
        k[i % g][s[i] - 'a']++;

    li ans = 0;

    for(int i = 0; i < y; i++)
        ans += k[i % g][t[i] - 'a'];

    li LCM = x * 1ll * y / g;
    ans = (LCM - ans) * (n * x / LCM);

    cout << ans;
}