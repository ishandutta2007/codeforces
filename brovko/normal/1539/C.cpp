#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int n, k, x, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <int> v;

    sort(a, a + n);

    for(int i = 1; i < n; i++)
        if(a[i] - a[i - 1] > x)
            v.pb((a[i] - a[i - 1] - 1) / x);

    sort(v.begin(), v.end());
    int ans = v.size() + 1;

    int x = 0;

    while(x < v.size() && v[x] <= k)
    {
        k -= v[x];
        ans--;
        x++;
    }

    cout << ans;
}