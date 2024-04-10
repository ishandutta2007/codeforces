#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, p, a, b, c;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> p >> a >> b >> c;

        cout << min({(a - p % a) % a, (b - p % b) % b, (c - p % c) % c}) << "\n";
    }
}