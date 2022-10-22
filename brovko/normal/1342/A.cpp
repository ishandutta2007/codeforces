#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int a, b, x, y, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> t;
    while(t--)
    {
        cin >> x >> y >> a >> b;
        if(x>y)
            swap(x, y);
        if(b>2*a)
            b=2*a;
        cout << b*x+a*(y-x) << "\n";
    }
}