#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[200005], b[200005], c[200005];
map <int, int> k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        k[a[i]]++;
    }

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < m; i++)
        cin >> c[i];

    int ans = 0;
    int x = 0, y = 0;

    for(int i = 0; i < m; i++)
    {
        if(k[b[i]] > x || (k[b[i]] == x && k[c[i]] > y))
        {
            ans = i;
            x = k[b[i]];
            y = k[c[i]];
        }
    }

    cout << ans + 1;
}