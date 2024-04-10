#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k;

        for(int i = 1; i < 2 * k - n; i++)
            cout << i << ' ';

        for(int i = k; i >= 2 * k - n; i--)
            cout << i << ' ';

        cout << "\n";
    }
}