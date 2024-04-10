#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, x;
        cin >> n >> x;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int Min = 1e9, Max = -1e9;

        for(int i = 0; i < n; i++)
        {
            Min = min(Min, a[i]);
            Max = max(Max, a[i]);
        }

        int d1 = max(0, Min - 1);
        int d2 = max(0, x - Max);

        int Maxlr = max(a[0], a[n - 1]);
        int Minlr = min(a[0], a[n - 1]);

        li ans = 0;

        for(int i = 1; i < n; i++)
            ans += abs(a[i] - a[i - 1]);

        cout << ans + min(2 * d1, Minlr - 1) + max(0, min(2 * d2, x - Maxlr)) << "\n";
    }
}