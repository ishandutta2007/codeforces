#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], ps[100005], Max[100005], Min[100005];

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
        if(i % 2)
            ps[i] = ps[i - 1] + abs(a[i] - a[i - 1]);
        else ps[i] = ps[i - 1] - abs(a[i] - a[i - 1]);
    }

    Max[n - 1] = ps[n - 1];
    Min[n - 1] = ps[n - 1];

    for(int i = n - 2; i >= 0; i--)
    {
        Max[i] = max(Max[i + 1], ps[i]);
        Min[i] = min(Min[i + 1], ps[i]);
    }

    int ans = -1e9;

    for(int i = 1; i < n; i++)
    {
        if(i % 2)
            ans = max(ans, Max[i] - ps[i - 1]);
        else ans = max(ans, ps[i - 1] - Min[i]);
    }

    cout << ans;
}