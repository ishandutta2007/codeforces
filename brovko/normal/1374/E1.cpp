#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, t[200005], a[200005], b[200005];
vector <int> v, u, q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> t[i] >> a[i] >> b[i];

        if(a[i] == 1 && b[i] == 1)
            q.push_back(t[i]);

        if(a[i] == 1 && b[i] == 0)
            v.push_back(t[i]);

        if(a[i] == 0 && b[i] == 1)
            u.push_back(t[i]);
    }

    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    for(int i = 0; i < min(v.size(), u.size()); i++)
        q.push_back(v[i] + u[i]);

    sort(q.begin(), q.end());

    if(q.size() < k)
    {
        cout << -1;
        return 0;
    }

    int ans = 0;

    for(int i = 0; i < k; i++)
        ans += q[i];

    cout << ans;
}