#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

using li = long long;
const int N = 1005;

int ee[N][N], oe[N][N], eo[N][N], oo[N][N];

int get_ee(int r1, int r2)
{
    int ans = 0;

    for(int i = r1; i >= 0; i = (i & i + 1) - 1)
        for(int j = r2; j >= 0; j = (j & j + 1) - 1)
            ans ^= ee[i][j];

    return ans;
}

int get_eo(int r1, int r2)
{
    int ans = 0;

    for(int i = r1; i >= 0; i = (i & i + 1) - 1)
        for(int j = r2; j >= 0; j = (j & j + 1) - 1)
            ans ^= eo[i][j];

    return ans;
}

int get_oe(int r1, int r2)
{
    int ans = 0;

    for(int i = r1; i >= 0; i = (i & i + 1) - 1)
        for(int j = r2; j >= 0; j = (j & j + 1) - 1)
            ans ^= oe[i][j];

    return ans;
}

int get_oo(int r1, int r2)
{
    int ans = 0;

    for(int i = r1; i >= 0; i = (i & i + 1) - 1)
        for(int j = r2; j >= 0; j = (j & j + 1) - 1)
            ans ^= oo[i][j];

    return ans;
}

void upd_ee(int x, int y, int val)
{
    for(int i = x; i < N; i |= i + 1)
        for(int j = y; j < N; j |= j + 1)
            ee[i][j] ^= val;
}

void upd_eo(int x, int y, int val)
{
    for(int i = x; i < N; i |= i + 1)
        for(int j = y; j < N; j |= j + 1)
            eo[i][j] ^= val;
}

void upd_oe(int x, int y, int val)
{
    for(int i = x; i < N; i |= i + 1)
        for(int j = y; j < N; j |= j + 1)
            oe[i][j] ^= val;
}

void upd_oo(int x, int y, int val)
{
    for(int i = x; i < N; i |= i + 1)
        for(int j = y; j < N; j |= j + 1)
            oo[i][j] ^= val;
}

void upd(int x, int y, int val)
{
    if(x % 2 == 0 && y % 2 == 0)
        upd_ee(x, y, val);
    else if(x % 2 == 0)
        upd_eo(x, y, val);
    else if(y % 2 == 0)
        upd_oe(x, y, val);
    else upd_oo(x, y, val);
}

int get(int x, int y)
{
    if(x % 2 == 0 && y % 2 == 0)
        return get_ee(x, y);
    else if(x % 2 == 0)
        return get_eo(x, y);
    else if(y % 2 == 0)
        return get_oe(x, y);
    else return get_oo(x, y);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int lx, rx, ly, ry;
            cin >> lx >> ly >> rx >> ry;

            cout << (get(rx, ry) ^ get(rx, ly - 1) ^ get(lx - 1, ry) ^ get(lx - 1, ly - 1)) << "\n";
        }
        else
        {
            int lx, rx, ly, ry, val;
            cin >> lx >> ly >> rx >> ry >> val;

            upd(rx + 1, ry + 1, val);
            upd(rx + 1, ly, val);
            upd(lx, ry + 1, val);
            upd(lx, ly, val);

//            for(int rx = 1; rx <= n; rx++)
//            {
//                for(int ry = 1; ry <= n; ry++)
//                    cout << get(rx, ry) << ' ';
//
//                cout << endl;
//            }
        }
    }
}