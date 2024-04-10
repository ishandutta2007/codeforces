#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;
const ld pi = 3.1415926535897932384626433832795028841;

int n, px, py, X[100005], Y[100005];

ld dist(ld x_1, ld y_1, ld x_2, ld y_2)
{
    return sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}

ld scal(ld x_1, ld y_1, ld x_2, ld y_2)
{
    return x_1 * x_2 + y_1 * y_2;
}

ld vect(ld x_1, ld y_1, ld x_2, ld y_2)
{
    return x_1 * y_2 - x_2 * y_1;
}

ld h(ld x_1, ld y_1, ld x_2, ld y_2)
{
    return abs(vect(x_1 - px, y_1 - py, x_2 - px, y_2 - py)) / sqrt((x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> px >> py;

    ld L = 1e18, R = -1e18;

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        X[i] = x;
        Y[i] = y;

        R = max(R, (ld)(x - px) * (x - px) + (ld)(y - py) * (y - py));
        L = min(L, (ld)(x - px) * (x - px) + (ld)(y - py) * (y - py));
    }

    X[n] = X[0];
    Y[n] = Y[0];

    for(int i = 0; i < n; i++)
    {
        ld a = dist(px, py, X[i], Y[i]), b = dist(px, py, X[i + 1], Y[i + 1]), c = dist(X[i], Y[i], X[i + 1], Y[i + 1]);

//        cout << a << ' ' << b << ' ' << c << endl;

        if(a * a + c * c > b * b && b * b + c * c > a * a)
            L = min(L, h(X[i], Y[i], X[i + 1], Y[i + 1]) * h(X[i], Y[i], X[i + 1], Y[i + 1]));
    }

//    cout << L << endl;

    cout << setprecision(20) << pi * (R - L);
}

/*
3 0 0
-1 1
1 1
1 3

*/