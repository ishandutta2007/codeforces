#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, d, m, a[100005], p[100005], s[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> d >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    p[0] = 0;

    int k = n - 1;
    int z = 0;

    while(k >= 0 && a[k] > m)
    {
        s[z + 1] = s[z] + a[k];
        k--;
        z++;
    }

    int z1 = 0;

    while(k >= 0)
    {
        p[z1 + 1] = p[z1] + a[k];
        k--;
        z1++;
    }

    int ans = 0;

    for(int i = 0; i <= z1; i++)
    {
        int x = min(z, (n + d - i) / (d + 1));

        ans = max(ans, p[i] + s[x]);
    }

    cout << ans;
}