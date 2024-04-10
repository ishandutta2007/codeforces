#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, k, s, a[200005], b[200005], t[200005], c[200005], Mx[200005], My[200005], psv[200005], psu[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k >> s;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];

    int x = 0, y = 0;

    for(int i = 0; i < m; i++)
    {
        cin >> t[i] >> c[i];

        if(t[i] == 1)
            x += c[i];
        else y += c[i];
    }

    int mx = 0, my = 0;

    for(int i = 0; i < n; i++)
    {
        if(a[i] < a[mx])
            mx = i;

        if(b[i] < b[my])
            my = i;

        Mx[i] = mx;
        My[i] = my;
    }

    vector <int> v, u;

    for(int i = 0; i < m; i++)
        if(t[i] == 1)
            v.pb(c[i]);
        else u.pb(c[i]);

    sort(v.begin(), v.end());
    sort(u.begin(), u.end());

    for(int i = 0; i < v.size(); i++)
        psv[i + 1] = psv[i] + v[i];

    for(int i = 0; i < u.size(); i++)
        psu[i + 1] = psu[i] + u[i];


//    for(int i = 0; i <= v.size(); i++)
//        cout << psv[i] << ' ';
//
//    cout << endl;
//
//    for(int i = 0; i <= u.size(); i++)
//        cout << psu[i] << ' ';
//
//    cout << endl;

    int L = -1, R = n;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int Min = s + 1;

        for(int i = 0; i <= v.size(); i++)
        {
            int j = k - i;

            if(j >= 0 && j <= u.size())
                Min = min(Min, psv[i] * a[Mx[M]] + psu[j] * b[My[M]]);
        }

        if(Min <= s)
            R = M;
        else L = M;
    }

    if(R == n)
        cout << -1;
    else
    {
        cout << R + 1 << "\n";

        vector <pair <int, int> > vp, up;

        for(int i = 0; i < m; i++)
            if(t[i] == 1)
                vp.pb({c[i], i});
            else up.pb({c[i], i});

        sort(vp.begin(), vp.end());
        sort(up.begin(), up.end());

        v.pb(2e12);
        u.pb(2e12);

        int x = 0, y = 0;


        for(int i = 0; i < k; i++)
        {
            if(v[x] * a[Mx[R]] < u[y] * b[My[R]])
            {
                cout << vp[x].y + 1 << ' ' << Mx[R] + 1 << "\n";
                x++;
            }
            else
            {
                cout << up[y].y + 1 << ' ' << My[R] + 1 << "\n";
                y++;
            }
        }
    }
}