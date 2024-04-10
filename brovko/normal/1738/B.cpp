#include <bits/stdc++.h>
//#define int long long
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

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector <int> a(k);

        for(int i = 0; i < k; i++)
            cin >> a[i];

        if(k == 1)
        {
            cout << "YES\n";
            continue;
        }

        bool F = 1;

        for(int i = 1; i < k - 1; i++)
            F &= (a[i] - a[i - 1] <= a[i + 1] - a[i]);

        F &= ((n - k + 1) * 1ll *  (a[1] - a[0]) >= a[0]);

        cout << (F ? "YES\n" : "NO\n");
    }
}