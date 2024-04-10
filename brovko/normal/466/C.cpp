#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[500005], ps[500005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0, ans = 0;

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];

    for(int i = 0; i < n - 1; i++)
    {
        if(ps[i + 1] * 3 == ps[n] * 2)
            ans += x;

        if(ps[i + 1] * 3 == ps[n])
            x++;
    }

    cout << ans;
}