#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, m, q, sx, sy, ex, ey, sc, ec;

int gcd(int x, int y)
{
    if(x==0 || y==0)
        return x+y;
    return gcd(y%x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m >> q;
    int a=n/gcd(n, m);
    int b=m/gcd(n, m);
    while(q--)
    {
        cin >> sx >> sy >> ex >> ey;
        sy--;
        ey--;
        if(sx==1)
            sc=sy/a;
        else sc=sy/b;
        if(ex==1)
            ec=ey/a;
        else ec=ey/b;
        if(sc==ec)
            cout << "YES\n";
        else cout << "NO\n";
    }
}