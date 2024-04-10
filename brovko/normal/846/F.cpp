#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[1000005], l[1000005], r[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = n - 1; i >= 0; i--)
    {
        if(l[a[i]] == 0)
            r[i] = n;
        else r[i] = l[a[i]];

        l[a[i]] = i;
    }

    int s = 0;

    for(int i = 0; i < n; i++)
    {
        s += 2 * (i + 1) * (r[i] - i) - 1;
    }

    cout << setprecision(20) << (ld)s / (n * n);
}