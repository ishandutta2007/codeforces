#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, used[1000005], t[1000005], a[1000005], root, st[1000005], T;
vector <int> g[1000005], ans;

void dfs(int v)
{
    used[v] = 1;

    for(auto to:g[v])
        if(used[to] == 0)
            {
                dfs(to);
                st[v] += st[to];
            }

    if(T % 3 == 0 && st[v] == T / 3 && v != root)
    {
        ans.push_back(v);
        st[v] = 0;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> t[i];

        a[i]--;

        if(a[i] == -1)
            root = i;
        else
        {
            g[i].push_back(a[i]);
            g[a[i]].push_back(i);
        }

        T += t[i];
        st[i] = t[i];
    }

    dfs(root);

    /*for(int i = 0; i < n; i++)
        cout << st[i] << ' ';
    cout << "\n";

    for(auto to:ans)
        cout << to << ' ';
    cout << "\n";*/

    if(ans.size() < 2)
        cout << -1;
    else cout << ans[0] + 1 << ' ' << ans[1] + 1;
}