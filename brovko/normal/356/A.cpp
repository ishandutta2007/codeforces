#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> ans(n + 1);
    set <int> q;

    for(int i = 1; i <= n; i++)
        q.insert(i);

    for(int i = 0; i < m; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;

        auto it = q.lower_bound(l);

        int L = l;

        while(it != q.end() && (*it) <= r)
        {
            if((*it) == x)
                L = x + 1;
            else
            {
                ans[(*it)] = x;
                q.erase(it);
            }

            it = q.lower_bound(L);
        }
    }

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}