#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        if(n > m)
        {
            cout << "0\n";
            continue;
        }

        m++;

        int i = 30;

        while(i >= 0 && ((n & (1 << i)) == 0 || (m & (1 << i)) != 0))
            i--;

        int ans = (n ^ m);

        i++;

//        cout << ans << ' ' << i << "\n";

        ans &= (~((1 << i) - 1));

        cout << ans << "\n";
    }
}