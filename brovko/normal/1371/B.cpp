#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        int n, r;

        cin >> n >> r;
        int ans = 0;

        if(n <= r)
        {
            r = n - 1;
            ans = 1;
        }

        cout << r * (r + 1) / 2 + ans << "\n";
    }
}