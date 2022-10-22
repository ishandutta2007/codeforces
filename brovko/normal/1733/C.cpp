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
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <pair <int, int> > v;

        cout << n - 1 << "\n";

        int mx = 0;

        for(int i = 0; i < n; i++)
            if(a[i] % 2 == a[0] % 2)
                mx = i;

        for(int i = 0; i < mx; i++)
            if(a[i] % 2 == a[0] % 2)
                cout << i + 1 << ' ' << mx + 1 << "\n";

        for(int i = 1; i < n; i++)
            if(a[i] % 2 != a[0] % 2)
                cout << 1 << ' ' << i + 1 << "\n";
    }
}