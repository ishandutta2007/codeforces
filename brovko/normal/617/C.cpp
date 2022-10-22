#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, x1, y1, x2, y2, x[2005], y[2005];
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x1 >> y1 >> x2 >> y2;

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        v.push_back({(x[i] - x1) * (x[i] - x1) + (y[i] - y1) * (y[i] - y1), (x[i] - x2) * (x[i] - x2) + (y[i] - y2) * (y[i] - y2)});
    }

    sort(v.begin(), v.end());

    int ans = v[n - 1].first;
    int Max = 0;

    for(int i = n - 1; i >= 1; i--)
    {
        Max = max(Max, v[i].second);
        ans = min(ans, Max + v[i - 1].first);
    }

    Max = max(Max, v[0].second);
    ans = min(ans, Max);

    cout << ans;
}