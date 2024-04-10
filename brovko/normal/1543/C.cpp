#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define p3 pair <ld, pair <ld, ld> >

using namespace std;
const ld eps = 1e-9;

int t;
ld c, m, p, v;
map <p3, ld> M;

ld f(ld c, ld m, ld p)
{
    if(M[{c, {m, p}}] > 0)
        return M[{c, {m, p}}];

    if(c > eps)
    {
        ld d = min(v, c);

        ld c1 = c - d, m1 = m, p1 = p;

        if(m <= eps)
            p1 += d;

        if(p <= eps)
            m1 += d;

        if(m > eps && p > eps)
        {
            p1 += d / 2;
            m1 += d / 2;
        }

        M[{c, {m, p}}] += c * f(c1, m1, p1);
    }

    if(m > eps)
    {
        ld d = min(v, m);

        ld c1 = c, m1 = m - d, p1 = p;

        if(c <= eps)
            p1 += d;

        if(p <= eps)
            c1 += d;

        if(c > eps && p > eps)
        {
            p1 += d / 2;
            c1 += d / 2;
        }

        M[{c, {m, p}}] += m * f(c1, m1, p1);
    }

    M[{c, {m, p}}]++;

    return M[{c, {m, p}}];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        M.clear();

        cin >> c >> m >> p >> v;
        cout << setprecision(20) << f(c, m, p) << "\n";
    }
}