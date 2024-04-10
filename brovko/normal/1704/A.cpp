#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        int Min = 1, Max = 0;

        for(int i = 0; i <= n - m; i++)
        {
            Min = min(Min, (int)a[i] - '0');
            Max = max(Max, (int)a[i] - '0');
        }

//        cout << Min << ' ' << Max << "\n";

        if(Min <= b[0] - '0' && Max >= b[0] - '0' && a.substr(n - m + 1, m - 1) == b.substr(1, m - 1))
            cout << "YES\n";
        else cout << "NO\n";
    }
}