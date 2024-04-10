#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k, a[150005], ps[150005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];

    int Min = 1e18, ans = 0;

    for(int i = 0; i <= n - k; i++)
    {
        if(ps[i + k] - ps[i] < Min)
        {
            Min = ps[i + k] - ps[i];
            ans = i;
        }
    }

    cout << ans + 1;
}