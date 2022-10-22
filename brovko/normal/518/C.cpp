#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, k, a[100005], b[100005], pos[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    int ans = 0;

    for(int i = 0; i < m; i++)
    {
        cin >> b[i];

//        cout << pos[b[i]] << endl;

        ans += pos[b[i]] / k + 1;

        if(pos[b[i]] > 0)
        {
            int x = pos[b[i]], y = x - 1;
            swap(a[x], a[y]);
            pos[a[x]] = x;
            pos[a[y]] = y;
        }
    }

    cout << ans;
}