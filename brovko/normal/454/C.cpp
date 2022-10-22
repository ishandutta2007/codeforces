#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int m, n;

ld binpow(ld x, int y)
{
    if(y == 0)
        return 1;

    if(y % 2)
        return x * binpow(x, y - 1);

    ld z = binpow(x, y / 2);

    return z * z;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    vector <ld> v;
    v.pb(0);

    for(int i = 1; i <= m; i++)
        v.pb(binpow((ld)i / m, n));

//    for(auto x:v)
//        cout << x << ' ';
//
//    cout << endl;

    ld ans = 0;

    for(int i = 1; i <= m; i++)
        ans += i * (v[i] - v[i - 1]);

    cout << setprecision(20) << ans;
}