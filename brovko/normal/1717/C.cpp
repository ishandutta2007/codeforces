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

        vector <int> a(n), b(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            cin >> b[i];

        bool F = 1;

        for(int i = 0; i < n; i++)
            if(a[i] > b[i] || a[i] != b[i] && b[i] > b[(i + 1) % n] + 1)
                F = 0;

        cout << (F ? "YES\n" : "NO\n");
    }
}