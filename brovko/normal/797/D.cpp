#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], l[100005], r[100005], p[100005];

map <int, int> f;

void dfs(int v, int Min, int Max)
{
    if(a[v] >= Min && a[v] <= Max)
        f[a[v]] = 1;

    if(l[v] >= 0)
    {
        dfs(l[v], Min, min(Max, a[v] - 1));
    }

    if(r[v] >= 0)
    {
        dfs(r[v], max(Min, a[v]), Max);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        p[i] = -1;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> l[i] >> r[i];
        l[i]--;
        r[i]--;

        p[l[i]] = i;
        p[r[i]] = i;
    }

    int root = 0;
    for(int i = 0; i < n; i++)
        if(p[i] == -1)
            root = i;

    dfs(root, -1e9, 1e9);
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(f[a[i]] == 0)
            ans++;
    }

    cout << ans;
}