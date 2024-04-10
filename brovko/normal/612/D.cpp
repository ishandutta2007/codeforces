#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, k, l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;

        v.pb({l, 1});
        v.pb({r + 1, -1});
    }

    sort(v.begin(), v.end());

    vector <int> ans;

    int x = 0;

    for(auto to:v)
    {
        if(to.y == 1)
        {
            x++;

            if(x == k)
                ans.pb(to.x);
        }
        else
        {
            x--;

            if(x == k - 1)
                ans.pb(to.x - 1);
        }
    }

    cout << ans.size() / 2 << "\n";

    for(int i = 0; i < ans.size(); i += 2)
        cout << ans[i] << ' ' << ans[i + 1] << "\n";
}