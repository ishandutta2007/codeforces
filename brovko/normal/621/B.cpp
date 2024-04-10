#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, x[200005], y[200005];

map <int, int> s, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        ans += s[x[i] + y[i]] + r[x[i] - y[i]];
        s[x[i] + y[i]]++;
        r[x[i] - y[i]]++;
    }

    cout << ans;
}