#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, m, a[300005], pos[300005], l, r;
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> l >> r;

        l = pos[l];
        r = pos[r];

        if(l > r)
            swap(l, r);

        v.push_back({r, l});
    }

    sort(v.begin(), v.end());

    int Max = -1;
    int x = 0;
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        while(x < m && i == v[x].first)
        {
            Max = max(Max, v[x].second);
            x++;
        }

        ans += i - Max;
    }

    cout << ans;
}