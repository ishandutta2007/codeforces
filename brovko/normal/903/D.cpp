#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], k;
map <int, int> m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int INF = (int)100;

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    int ans = 0;
    int s = 0;

    for(int i=0; i<n; i++)
    {
        ans += a[i] * (i - m[a[i]] - m[a[i] + 1] - m[a[i] - 1]) - s + a[i] * m[a[i]] + (a[i] + 1) * m[a[i] + 1] + (a[i] - 1) * m[a[i] - 1];

        if(ans >= INF || ans <= -INF)
            {
                k += ans / INF;
                ans %= INF;
            }

        s += a[i];
        m[a[i]]++;
    }

    //cout << k << ' ' << ans << endl;

    if(k < 0 || (k == 0 && ans < 0))
        {
            cout << '-';
            k = -k;
            ans = -ans;
        }

    cout << (unsigned long long)k * INF + ans;
}