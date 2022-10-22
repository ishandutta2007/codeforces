#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], b[100005], h[100005], dp[100005], t[400005];
vector <pair <int, int> > v;

bool comp(pair <int, int> i, pair <int, int> j)
{
    if(i.first < j.first)
        return true;

    if(i.first > j.first)
        return false;

    return a[i.second] < a[j.second];
}

int get(int v, int l, int r, int L, int R)
{
    if(L == l && R == r)
        return t[v];

    if(L >= R)
        return 0;

    int m = (l + r) / 2;

    return max(get(2 * v + 1, l, m, L, min(m, R)), get(2 * v + 2, m, r, max(m, L), R));
}

void update(int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        t[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        update(2 * v + 1, l, m, pos, val);
    else update(2 * v + 2, m, r, pos, val);

    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> h[i];

        v.push_back({b[i], i});
    }

    sort(v.begin(), v.end(), comp);

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        dp[i] = h[v[i].second];

        int L = -1;
        int R = i;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(v[M].first > a[v[i].second])
                R = M;
            else L = M;
        }

        dp[i] += get(0, 0, n, R, i);

        update(0, 0, n, i, dp[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans;
}