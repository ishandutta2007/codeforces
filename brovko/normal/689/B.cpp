#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, a[200005], used[200005], ans[200005];
vector <int> g[200005];
queue <int> q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        g[i].push_back(a[i] - 1);

    for(int i = 0; i < n - 1; i++)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }

    q.push(0);
    used[0] = 1;

    while(!q.empty())
    {
        int x = q.front();

        for(auto to:g[x])
        {
            if(used[to] == 0)
            {
                used[to] = 1;
                q.push(to);
                ans[to] = ans[x] + 1;
            }
        }

        q.pop();
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}