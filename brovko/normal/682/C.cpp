#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, a[100005], p[100005], c[100005];
vector <int> g[100005];

void dfs(int v, int s)
{
    if(s > a[v])
        a[v] = -1;
        
    if(a[p[v]] < 0)
        a[v] = -1;

    for(auto to:g[v])
    {
        dfs(to, max(0ll, s + c[to]));
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

    for(int i = 1; i < n; i++)
    {
        cin >> p[i] >> c[i];
        p[i]--;

        g[p[i]].push_back(i);
    }

    dfs(0, 0);

    int k = 0;

    for(int i = 0; i < n; i++)
        if(a[i] < 0)
            k++;

    cout << k;
}