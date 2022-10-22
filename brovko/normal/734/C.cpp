#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, x, s, a[200005], b[200005], c[200005], d[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    cin >> x >> s;

    for(int i = 0; i < m; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    for(int i = 0; i < k; i++)
        cin >> c[i];

    for(int i = 0; i < k; i++)
        cin >> d[i];

    int ans = 9e18;

    for(int i = 0; i < m; i++)
    {
        int L = -1;
        int R = k;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(d[M] <= s - b[i])
                L = M;
            else R = M;
        }

        if(L != -1)
        {
            ans = min(ans, (n - c[L]) * a[i]);
        }
    }

    int Max = 0;

    for(int i = 0; i < k; i++)
    {
        if(d[i] <= s)
            Max = c[i];
    }

    ans = min(ans, (n - Max) * x);
    
    int Min = x;
    
    for(int i = 0; i < m; i++)
    {
        if(b[i] <= s)
            Min = min(Min, a[i]);
    }
    
    ans = min(ans, n * Min);

    cout << ans;
}