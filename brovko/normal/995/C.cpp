#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const int N = 1500000;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    int xx = 0, yy = 0;

    vector <int> vx(n), vy(n), x(n), y(n), ans(n);

    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];

        if((xx + x[i]) * (xx + x[i]) + (yy + y[i]) * (yy + y[i]) < (xx - x[i]) * (xx - x[i]) + (yy - y[i]) * (yy - y[i]))
        {
            xx += x[i];
            yy += y[i];
            ans[i] = 1;
        }
        else
        {
            xx -= x[i];
            yy -= y[i];
            ans[i] = -1;
        }

        vx[i] = xx;
        vy[i] = yy;
    }

    int X1, Y1, X2, Y2;

    X1 = vx[n - 1];
    Y1 = vy[n - 1];
    X2 = vx[n - 1] - 2 * ans[n - 1] * x[n - 1];
    Y2 = vy[n - 1] - 2 * ans[n - 1] * y[n - 1];

    for(int i = n - 2; i >= 0; i--)
    {
        if(X1 * X1 + Y1 * Y1 > N * N && X2 * X2 + Y2 * Y2 > N * N)
        {
            ans[i] = -ans[i];

            X1 += ans[i] * x[i] * 2;
            X2 += ans[i] * x[i] * 2;
            Y1 += ans[i] * y[i] * 2;
            Y2 += ans[i] * y[i] * 2;
        }
    }

    if(X2 * X2 + Y2 * Y2 <= N * N)
    {
        ans[n - 1] = -ans[n - 1];
        swap(X1, X2);
        swap(Y1, Y2);
    }

    assert(X1 * X1 + Y1 * Y1 <= N * N);

    for(auto x:ans)
        cout << x << ' ';

//    int last = n - 1;
//
//    for(int i = n - 1; i >= 0; i--)
//    {
//        if(vx[last] * vx[last] + vy[last] * vy[last] > N * N)
//        {
//            ans[i] = -ans[i];
//
//            if(ans[i] == 1)
//            {
//                vx[last] += x[i] * 2;
//                vy[last] += y[i] * 2;
//            }
//            else
//            {
//                vx[last] -= x[i] * 2;
//                vy[last] -= y[i] * 2;
//            }
//        }
//        else last = i;
//    }
//
//    for(int i = 0; i < n; i++)
//    {
//        ans[i] =
//    }
}