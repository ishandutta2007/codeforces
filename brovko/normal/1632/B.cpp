#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, a[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int x = 1;

        while(n - 1 >= x)
            x *= 2;

        x /= 2;

        for(int i = n - 1; i >= x; i--)
            cout << i << ' ';

        for(int i = 0; i < x; i++)
            cout << i << ' ';

        cout << "\n";
    }
}