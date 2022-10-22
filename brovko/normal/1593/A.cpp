#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        cout << max(0ll, max(b, c) + 1 - a) << ' ' << max(0ll, max(a, c) + 1 - b) << ' ' << max(0ll, max(a, b) + 1 - c) << "\n";
    }
}