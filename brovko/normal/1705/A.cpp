#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

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

        vector <int> a(2 * n);

        for(int i = 0; i < 2 * n; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        bool F = 1;

        for(int i = 0; i < n; i++)
            F &= (a[i + n] - a[i] >= x);

        cout << (F ? "YES\n" : "NO\n");
    }
}