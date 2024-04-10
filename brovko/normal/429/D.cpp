#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = 1e9;

    for(int i = 1; i < n; i++)
        ans = min(ans * 1ll, a[i] * 1ll * a[i] + 1);

    for(int i = 0; i < n; i++)
    {
        int s = 0;

        for(int j = i + 1; ((j - i) * (j - i) < ans && j < n); j++)
        {
            s += a[j];
            ans = min(ans * 1ll, s * 1ll * s + (j - i) * 1ll * (j - i));
        }
    }

    cout << ans;
}