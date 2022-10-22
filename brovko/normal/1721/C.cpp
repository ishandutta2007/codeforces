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

        vector <int> b(n);

        for(int i = 0; i < n; i++)
            cin >> b[i];

        for(int i = 0; i < n; i++)
        {
            cout << (*lower_bound(b.begin(), b.end(), a[i])) - a[i] << ' ';
        }

        cout << "\n";

        vector <int> rg(n, n - 1);

        for(int i = n - 2; i >= 0; i--)
        {
            if(a[i + 1] > b[i])
                rg[i] = i;
            else rg[i] = rg[i + 1];
        }

        for(int i = 0; i < n; i++)
            cout << b[rg[i]] - a[i] << ' ';

        cout << "\n";
    }
}