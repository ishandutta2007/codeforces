#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

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

        int Max = 0, s = 0;

        for(int i = 0; i < n; i++)
        {
            Max = max(Max, a[i]);
            s += a[i];
        }

        cout << max(Max, (s + n - 2) / (n - 1)) * (n - 1) - s << "\n";
    }
}