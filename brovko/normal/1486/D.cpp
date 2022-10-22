#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;



int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n];

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int L = 1, R = n + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int ps[n + 1];
        int mn[n + 1];

        ps[0] = 0;
        mn[0] = 0;

        for(int i = 0; i < n; i++)
        {
            ps[i + 1] = ps[i];

            if(a[i] >= M)
                ps[i + 1]++;
            else ps[i + 1]--;

            mn[i + 1] = min(mn[i], ps[i + 1]);
        }

        int ans = -1e9;

        for(int i = k; i <= n; i++)
            ans = max(ans, ps[i] - mn[i - k]);

        if(ans > 0)
            L = M;
        else R = M;
    }

    cout << L;
}