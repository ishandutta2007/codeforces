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

        for(int i = 0; i < n; i++)
            cin >> a[i];

        for(int i = 0; i < n; i++)
            if(a[i] > a[i % k])
                swap(a[i], a[i % k]);

        li ans = 0;

        for(int i = 0; i < k; i++)
            ans += a[i];

        cout << ans << "\n";
    }
}