#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int ax, ay, bx, by, tx, ty, n, x[100005], y[100005];

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> ax >> ay >> bx >> by >> tx >> ty >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int a = 0, b = 0;

    for(int i = 0; i < n; i++)
    {
        if(dist(x[i], y[i], ax, ay) - dist(x[i], y[i], tx, ty) < dist(x[a], y[a], ax, ay) - dist(x[a], y[a], tx, ty))
            a = i;

        if(dist(x[i], y[i], bx, by) - dist(x[i], y[i], tx, ty) < dist(x[b], y[b], bx, by) - dist(x[b], y[b], tx, ty))
            b = i;
    }

    ld a1 = dist(x[a], y[a], ax, ay) - dist(x[a], y[a], tx, ty);
    ld b1 = dist(x[b], y[b], bx, by) - dist(x[b], y[b], tx, ty);

    if(a == b && max(a1, b1) < 0)
    {
        a++;
        ld Min = min(a1, b1);

        for(int i = 0; i < n; i++)
            if(i != b)
        {
            Min = min(Min, min(b1 + dist(x[i], y[i], ax, ay) - dist(x[i], y[i], tx, ty), a1 + dist(x[i], y[i], bx, by) - dist(x[i], y[i], tx, ty)));
        }

        a1 = 0;
        b1 = Min;
    }

    ld ans = min(min(a1, b1), a1 + b1);
    
    if(a == b)
        ans = min(a1, b1);

    for(int i = 0; i < n; i++)
        ans += 2 * dist(x[i], y[i], tx, ty);

    cout << setprecision(20) << ans;
}