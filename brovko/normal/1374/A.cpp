#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, x, y, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> x >> y >> n;

        int z = n / x;

        if(z * x + y <= n)
            cout << z * x + y;
        else cout << (z - 1) * x + y;

        cout << "\n";
    }
}