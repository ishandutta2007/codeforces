#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int n, a[200005], b[200005], Min[200005][20], Max[200005][20];

int getmin(int l, int r)
{
    int ans = 1e9;

    for(int k = 19; k >= 0; k--)
        if(l + (1ll << k) - 1 <= r)
    {
        ans = min(ans, Min[l][k]);

        l += (1ll << k);
    }

    return ans;
}

int getmax(int l, int r)
{
    int ans = -1e9;

    for(int k = 19; k >= 0; k--)
        if(l + (1ll << k) - 1 <= r)
    {
        ans = max(ans, Max[l][k]);

        l += (1ll << k);
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++)
    {
        Min[i][0] = b[i];
        Max[i][0] = a[i];
    }

    for(int k = 1; k < 20; k++)
        for(int i = 0; i + (1ll << k) <= n; i++)
    {
        Max[i][k] = max(Max[i][k - 1], Max[i + (1ll << k - 1)][k - 1]);
        Min[i][k] = min(Min[i][k - 1], Min[i + (1ll << k - 1)][k - 1]);
    }

    int ans = 0;

    int l = 0;
    int L = 0;

    for(int i = 0; i < n; i++)
    {
        while(L <= i && getmin(L, i) < getmax(L, i))
            L++;

        while(l <= i && getmin(l, i) <= getmax(l, i))
            l++;

        ans += l - L;
    }

    cout << ans;
}