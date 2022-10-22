#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define matrix vector <vector <int> >

using namespace std;

int n, x, y, dx, dy, t, N;
matrix O, E;

int add(int x, int y)
{
    return ((x + y) % n + n) % n;
}

int mul(int x, int y)
{
    return x * y % n;
}

matrix mul(matrix x, matrix y)
{
    matrix ans = O;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                ans[i][j] = add(ans[i][j], mul(x[i][k], y[k][j]));

    return ans;
}

matrix binpow(matrix x, int y)
{
    if(y == 0)
        return E;

    if(y % 2)
        return mul(x, binpow(x, y - 1));

    matrix z = binpow(x, y / 2);

    return mul(z, z);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x >> y >> dx >> dy >> t;

    x--;
    y--;

    N = 7; // x, y, dx, dy, k, t, 1

    vector <int> v;

    for(int i = 0; i < N; i++)
        v.pb(0);

    for(int i = 0; i < N; i++)
        O.pb(v);

    E = O;

    for(int i = 0; i < N; i++)
        E[i][i] = 1;

    matrix M = O;

    M[0][0] = 1;
    M[2][0] = 1;
    M[4][0] = 1;

    M[1][1] = 1;
    M[3][1] = 1;
    M[4][1] = 1;

    M[2][2] = 1;
    M[4][2] = 1;

    M[3][3] = 1;
    M[4][3] = 1;

    M[0][4] = 1;
    M[1][4] = 1;
    M[2][4] = 1;
    M[3][4] = 1;
    M[4][4] = 2;
    M[5][4] = 1;
    M[6][4] = 3;

    M[5][5] = 1;
    M[6][5] = 1;

    M[6][6] = 1;

//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//            cout << M[i][j] << ' ';
//
//        cout << endl;
//    }

    M = binpow(M, t);

//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//            cout << M[i][j] << ' ';
//
//        cout << endl;
//    }

    int k = x + y + 2;

    int X = (M[0][0] * x % n + M[1][0] * y % n + M[2][0] * dx % n + M[3][0] * dy % n + M[4][0] * k % n + M[6][0]) % n;
    int Y = (M[0][1] * x % n + M[1][1] * y % n + M[2][1] * dx % n + M[3][1] * dy % n + M[4][1] * k % n + M[6][1]) % n;

    X = add(X, 0);
    Y = add(Y, 0);

    X++;
    Y++;

    cout << X << ' ' << Y;
}