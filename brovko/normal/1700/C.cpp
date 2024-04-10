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
        int n;
        cin >> n;

        vector <li> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        li ans = 0;

        for(int i = 0; i < n - 1; i++)
        {
            ans += abs(a[i] - a[i + 1]);

            if(a[i] > a[i + 1])
                a[0] -= (a[i] - a[i + 1]);
        }

        cout << ans + abs(a[0]) << "\n";
    }
}