#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b, x, y, z;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> x >> y >> z;

    cout << max(0ll, x * 2 + y - a) + max(0ll, z * 3 + y - b);
}