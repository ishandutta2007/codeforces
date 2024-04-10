#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x1, y1, x2, y2, x3, y3;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << "3\n";

    cout << x1 + x2 - x3 << ' ' << y1 + y2 - y3 << "\n";
    cout << x2 + x3 - x1 << ' ' << y2 + y3 - y1 << "\n";
    cout << x3 + x1 - x2 << ' ' << y3 + y1 - y2;
}