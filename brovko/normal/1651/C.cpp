#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[200005], b[200005], Min[4];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < 4; i++)
            Min[i] = 1e18;

        for(int i = 0; i < n; i++)
        {
            Min[0] = min(Min[0], abs(a[0] - b[i]));
            Min[1] = min(Min[1], abs(b[0] - a[i]));
            Min[2] = min(Min[2], abs(a[n - 1] - b[i]));
            Min[3] = min(Min[3], abs(b[n - 1] - a[i]));
        }

        cout << min({abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]), abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]), abs(a[0] - b[0]) + Min[2] + Min[3], abs(a[0] - b[n - 1]) + Min[1] + Min[2], abs(a[n - 1] - b[0]) + Min[0] + Min[3], abs(a[n - 1] - b[n - 1]) + Min[0] + Min[1], Min[0] + Min[1] + Min[2] + Min[3]}) << "\n";
    }
}