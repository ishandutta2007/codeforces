#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        int x = n;
        cout << 2 << "\n";

        for(int i = n - 1; i >= 1; i--)
        {
            cout << i << ' ' << x << "\n";
            x = (i + x + 1) / 2;
        }
    }
}