#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int f14, f13, f12, p1, f23, f24, f21, p2, f34, f31, f32, p3, f41, f42, f43, p4;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> f14 >> f13 >> f12 >> p1 >> f21 >> f24 >> f23 >> p2 >> f32 >> f31 >> f34 >> p3 >> f43 >> f42 >> f41 >> p4;

    if(p1 && (f14 || f13 || f12 || f21 || f31 || f41))
    {
        cout << "YES";
        return 0;
    }

    if(p2 && (f21 || f23 || f24 || f12 || f32 || f42))
    {
        cout << "YES";
        return 0;
    }

    if(p3 && (f13 || f23 || f43 || f31 || f32 || f34))
    {
        cout << "YES";
        return 0;
    }

    if(p4 && (f14 || f24 || f34 || f41 || f42 || f43))
    {
        cout << "YES";

        //cout << f14 << ' '  << f24 << ' ' << f34 << ' ' << f41 << ' ' << f42 << ' ' << f43;
        return 0;
    }

    cout << "NO";
}