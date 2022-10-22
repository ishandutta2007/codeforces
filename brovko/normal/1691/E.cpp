#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define x first
#define y second
#define pii pair <int, int>

using namespace std;
const int N = 100005;

int t, n, c[N], l[N], r[N], y, used[N][2];
pii tb[4 * N], tr[4 * N];
vector <pair <int, int> > red, blue;

pii get(pii* t, int v, int l, int r, int L, int R)
{
    if(L >= R)
        return {-2e9, 0};

    if(L == l && R == r)
        return t[v];

    int m = (l + r) / 2;

    return max(get(t, 2 * v + 1, l, m, L, min(m, R)), get(t, 2 * v + 2, m, r, max(L, m), R));
}

void update(pii* t, int v, int l, int r, int pos, pii val)
{
    if(r - l == 1)
    {
        t[v] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        update(t, 2 * v + 1, l, m, pos, val);
    else update(t, 2 * v + 2, m, r, pos, val);

    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

void dfs(int i, int f)
{
//    cout << "dfs " << i << ' ' << f << endl;

    used[i][f] = 1;

    if(f == 0)
    {
        int L = -1;
        int R = blue.size();

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(blue[M] <= (pii){red[i].y, 2e9})
                L = M;
            else R = M;
        }

        pii to = get(tb, 0, 0, n, 0, R);

        if(to.x >= red[i].x)
        {
            update(tb, 0, 0, n, to.y, {-1e18, to.y});
            dfs(to.y, 1);
            dfs(i, 0);
        }
    }
    else
    {
        int L = -1;
        int R = red.size();

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(red[M] <= (pii){blue[i].y, 2e9})
                L = M;
            else R = M;
        }

        pii to = get(tr, 0, 0, n, 0, R);

        if(to.x >= blue[i].x)
        {
            update(tr, 0, 0, n, to.y, {-1e18, to.y});
            dfs(to.y, 0);
            dfs(i, 1);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> c[i] >> l[i] >> r[i];

//        vector <int> u;
//
//        for(int i = 0; i < n; i++)
//        {
//            u.pb(l[i]);
//            u.pb(r[i]);
//        }
//
//        sort(u.begin(), u.end());
//
//        map <int, int> m;
//        y = 0;
//
//        for(int i = 0; i < u.size(); i++)
//        {
//            if(i == 0 || u[i] != u[i - 1])
//                y++;
//
//            m[u[i]] = y;
//        }
//
//        y++;
//
//        for(int i = 0; i < n; i++)
//        {
//            l[i] = m[l[i]];
//            r[i] = m[r[i]];
//        }

        red.clear();
        blue.clear();

        for(int i = 0; i < n; i++)
        {
            if(c[i] == 0)
            {
                red.pb({l[i], r[i]});
            }
            else
            {
                blue.pb({l[i], r[i]});
            }
        }

        sort(red.begin(), red.end());
        sort(blue.begin(), blue.end());

        for(int i = 0; i < red.size(); i++)
            update(tr, 0, 0, n, i, {red[i].y, i});

        for(int i = 0; i < blue.size(); i++)
            update(tb, 0, 0, n, i, {blue[i].y, i});

//        cout << "Red : ";
//
//        for(int i = 0; i < red.size(); i++)
//            cout << red[i].x << ' ' << red[i].y << "\n";
//
//        cout << "\n";
//
//        cout << "Blue : ";
//
//        for(int i = 0; i < blue.size(); i++)
//            cout << blue[i].x << ' ' << blue[i].y << "\n";
//
//        cout << "\n";
//
//        cout << "! " << get(tb, 0, 0, n, 0, blue.size()).x << endl;


        int ans = 0;

        for(int i = 0; i < red.size(); i++)
            if(used[i][0] == 0)
            {
                ans++;
                dfs(i, 0);
            }

        for(int i = 0; i < blue.size(); i++)
            if(used[i][1] == 0)
            {
                ans++;
                dfs(i, 1);
            }

        cout << ans << "\n";



        for(int i = 0; i < n; i++)
            for(int j = 0; j < 2; j++)
                used[i][j] = 0;

        for(int i = 0; i < 4 * n; i++)
        {
            tb[i] = {-2e9, -2e9};
            tr[i] = {-2e9, -2e9};
        }
    }
}

/*
1
5
0 0 5
1 2 12
0 4 7
1 9 16
0 13 19

*/