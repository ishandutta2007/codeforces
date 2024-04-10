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

        vector <int> a(n);
        int s = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }

        cout << (s ? "YES\n" : "NO\n");
    }
}