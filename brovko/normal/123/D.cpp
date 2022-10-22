#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

string s;
int n, p[100005], c[100005], pn[100005], cn[100005], cnt[100005], y, t[400020], tx[400020], tp[400020];

void push(int v, int l, int r)
{
    int m = (l + r) / 2;

    if(tx[v] > 0)
    {
        tx[2 * v + 1] = tx[v];
        tx[2 * v + 2] = tx[v];
        tp[2 * v + 1] = 0;
        tp[2 * v + 2] = 0;
        t[2 * v + 1] = tx[v] * (m - l);
        t[2 * v + 2] = tx[v] * (r - m);
        tx[v] = 0;
    }

    if(tp[v] > 0)
    {
        tp[2 * v + 1] += tp[v];
        tp[2 * v + 2] += tp[v];
        t[2 * v + 1] += tp[v] * (m - l);
        t[2 * v + 2] += tp[v] * (r - m);
        tp[v] = 0;
    }
}

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 0;

    if(tx[v] > 0)
        return tx[v] * (R - L) + tp[v] * (R - L);

    if(L == l && R == r)
        return t[v];

    push(v, l, r);
    int m = (l + r) / 2;

    return get(2 * v + 1, l, m, L, min(m, R)) + get(2 * v + 2, m, r, max(L, m), R);
}

void update(int v, int l, int r, int L, int R, int x, int p)
{
    if(L >= R)
        return;

    if(L == l && R == r)
    {
        if(x > 0)
        {
            tx[v] = x;
            tp[v] = 0;
            t[v] = x * (r - l);
        }

        tp[v] += p;
        t[v] += p * (r - l);
        return;
    }

    push(v, l, r);
    int m = (l + r) / 2;

    update(2 * v + 1, l, m, L, min(m, R), x, p);
    update(2 * v + 2, m, r, max(L, m), R, x, p);

    t[v] = t[2 * v + 1] + t[2 * v + 2];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    cin >> n;
//
//    while(true)
//    {
//        int t;
//        cin >> t;
//
//        if(t == 1)
//        {
//            int l, r;
//            cin >> l >> r;
//
//            cout << get(0, 0, n, l - 1, r) << endl;
//        }
//
//        if(t == 2)
//        {
//            int l, r, x;
//            cin >> l >> r >> x;
//
//            update(0, 0, n, l - 1, r, x, 0);
//        }
//
//        if(t == 3)
//        {
//            int l, r, p;
//            cin >> l >> r >> p;
//
//            update(0, 0, n, l - 1, r, 0, p);
//        }
//    }

    cin >> s;
    s += (char)0;
    n = s.size();

    vector <vector <int> > v;

    for(int i = 0; i < n; i++)
        cnt[s[i]]++;

    for(int i = 1; i < 128; i++)
        cnt[i] += cnt[i - 1];

    for(int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;

    for(int i = 0; i < n; i++)
    {
        if(i == 0 || s[p[i]] != s[p[i - 1]])
            y++;

        c[p[i]] = y - 1;
    }

    for(int j = 0; (1ll << j) < n; j++)
    {
        vector <int> u;

        for(int i = 0; i < n; i++)
            u.pb(c[i]);

        v.pb(u);

        for(int i = 0; i < n; i++)
        {
            pn[i] = p[i] - (1ll << j);

            while(pn[i] < 0)
                pn[i] += n;
        }

        for(int i = 0; i < y; i++)
            cnt[i] = 0;

        for(int i = 0; i < n; i++)
            cnt[c[i]]++;

        for(int i = 1; i < y; i++)
            cnt[i] += cnt[i - 1];

        for(int i = n - 1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];

        y = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0 || c[p[i]] != c[p[i - 1]] || c[(p[i] + (1ll << j)) % n] != c[(p[i - 1] + (1ll << j)) % n])
                y++;

            cn[p[i]] = y - 1;
        }

        for(int i = 0; i < n; i++)
            c[i] = cn[i];
    }

    vector <int> u;

    for(int i = 0; i < n; i++)
        u.pb(c[i]);

    v.pb(u);
    int ans = 0;

    for(int i = 1; i < n; i++)
    {
        int x = p[i], y = p[i - 1], lcp = 0;

        for(int j = (int)v.size() - 1; j >= 0; j--)
        {
            if(v[j][x] == v[j][y])
            {
                x += (1ll << j);
                y += (1ll << j);
                lcp += (1ll << j);
            }
        }

        update(0, 0, n, 0, lcp, 0, 1);
        update(0, 0, n, lcp, n - p[i] - 1, 1, 0);
        ans += get(0, 0, n, 0, n - p[i] - 1);
//        cout << ans << endl;
    }

    cout << ans;
}