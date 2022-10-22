#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        int s = 0;

        for(int i = 0; i < n - 1; i++)
            s += a[i];

        cout << setprecision(20) << a[n - 1] + (ld)s / (n - 1) << "\n";
    }
}