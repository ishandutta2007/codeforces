#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, l[200005], r[200005], y, a[200005], t[200005], ans[200005];
vector <int> v;
map <int, int> m;
vector <pair <int, int> > u;

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i < y; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];

        v.push_back(r[i]);
        u.push_back({l[i], i});
    }

    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    y = 1;

    for(auto to:v)
    {
        if(m[to] == 0)
        {
            m[to] = y;
            a[y] = to;
            y++;
        }
    }

    for(int i = n - 1; i >= 0; i--)
    {
        ans[u[i].second] = sum(m[r[u[i].second]]);

        inc(m[r[u[i].second]], 1);
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << "\n";
}