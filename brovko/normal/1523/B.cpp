#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, a[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        cout << 3 * n << "\n";

        for(int i = 1; i < n; i += 2)
        {
            cout << 1 << ' ' << i << ' ' << i + 1 << "\n";
            cout << 2 << ' ' << i << ' ' << i + 1 << "\n";
            cout << 1 << ' ' << i << ' ' << i + 1 << "\n";
            cout << 2 << ' ' << i << ' ' << i + 1 << "\n";
            cout << 1 << ' ' << i << ' ' << i + 1 << "\n";
            cout << 2 << ' ' << i << ' ' << i + 1 << "\n";
        }
    }
}