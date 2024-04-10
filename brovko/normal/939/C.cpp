#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], s, f, ps[200005], ans;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ans = 1e9;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
    }

    cin >> s >> f;

    for(int i=0; i<2*n; i++)
        ps[i + 1] = ps[i] + a[i];

    int Max = f - s;
    for(int i = f - s; i < 2 * n; i++)
    {
        if(ps[i] - ps[i - f + s] > ps[Max] - ps[Max - f + s])
            Max = i;
    }

    for(int i = f - s; i < 2 * n; i++)
    {
        if(ps[i] - ps[i - f + s] == ps[Max] - ps[Max - f + s])
            {
                int x = f - i;
                while(x < 1)
                    x += n;
                while(x > n)
                    x -= n;

                ans = min(ans, x);
            }
    }

    cout << ans;
}