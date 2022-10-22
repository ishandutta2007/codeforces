#include <bits/stdc++.h>
//#define int long long
#define ld long double

using namespace std;

int a[6], n, b[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 6; i++)
        cin >> a[i];

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + 6);
    sort(b, b + n);

    b[n] = 2e9;
    int ans = 2e9;

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < n; j++)
            if(b[j] - a[i] >= b[n - 1] - a[5])
            {
                int l = b[0] - a[0];

                for(int k = 0; k < 5; k++)
                    l = min(l, b[upper_bound(b, b + n, a[k] + b[j] - a[i]) - b] - a[k + 1]);

                ans = min(ans, b[j] - a[i] - l);
            }

    cout << ans;
}