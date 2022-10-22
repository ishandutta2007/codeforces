#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[200005], b[200005], u[200005], siz[200005], used[200005];

void dfs(int v)
{
    siz[v] = 1;
    used[v] = 1;

    if(b[v] >= 0)
    {
        if(used[b[v]] == 0)
            dfs(b[v]);
        siz[v] += siz[b[v]];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;

        if(b[i] >= 0)
            u[b[i]]++;
    }

    for(int i = 0; i < n; i++)
        if(u[i] == 0)
            dfs(i);

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
        v.push_back({siz[i], i});

    sort(v.begin(), v.end());

    vector <int> u;

    int ans = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        int x = v[i].second;

        if(a[x] >= 0)
        {
            if(b[x] >= 0)
                a[b[x]] += a[x];

            ans += a[x];

            u.push_back(x + 1);
        }
    }

    for(auto to:v)
    {
        int x = to.second;

        if(a[x] < 0)
        {
            ans += a[x];
            u.push_back(x + 1);
        }
    }

    cout << ans << "\n";

    for(auto to:u)
        cout << to << ' ';
}