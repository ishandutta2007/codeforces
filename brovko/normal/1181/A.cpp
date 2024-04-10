#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x, y, z;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> x >> y >> z;
    if(x/z+y/z==(x+y)/z)
        cout << (x+y)/z << " 0"; else
    cout << (x+y)/z << ' ' << min(z-x%z, z-y%z);
}