#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, a[55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int ans = 0;

    for(int i = 0; i < n; i++)
        if(a[i] >= a[n - k] && a[i] > 0)
            ans++;

    cout << ans;
}