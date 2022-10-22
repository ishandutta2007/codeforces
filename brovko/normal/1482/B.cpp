#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, k1, k2, w, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> k1 >> k2 >> w >> b;

        if(w <= (k1 + k2) / 2 && b <= (n - k1 + n - k2) / 2)
            cout << "YES\n";
        else cout << "NO\n";
    }
}