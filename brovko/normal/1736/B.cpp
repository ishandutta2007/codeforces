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

        vector <int> b(n + 1);

        b[0] = a[0], b[n] = a[n - 1];

        for(int i = 1; i < n; i++)
            b[i] = a[i - 1] * a[i] / __gcd(a[i - 1], a[i]);

        bool F = 1;

        for(int i = 0; i < n; i++)
            F &= (a[i] == __gcd(b[i], b[i + 1]));

        cout << (F ? "YES\n" : "NO\n");
    }
}