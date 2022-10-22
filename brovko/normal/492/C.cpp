#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, r, avg, a[100005], b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> avg;

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int s = 0;
    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        s += a[i];
        v.pb({b[i], i});
    }

    sort(v.begin(), v.end());
    int ans = 0;

    for(int i = 0; i < v.size(); i++)
    {
        int k = max(0ll, min(avg * n - s, r - a[v[i].y]));
        ans += v[i].x * k;
        s += k;
    }

    cout << ans;
}