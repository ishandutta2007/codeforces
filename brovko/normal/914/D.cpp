#include <bits/stdc++.h>
//#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, a[500005], t[4000005], p;

int gcd(int x, int y)
{
    if(x==0)
        return y;

    return gcd(y%x, x);
}

void build(int v, int l, int r)
{
    if(r-l==1)
    {
        t[v]=a[l];
        return;
    }

    int m = ((l + r) >> 1);
    build((v << 1) + 1, l, m);
    build((v << 1) + 2, m, r);
    t[v]=gcd(t[(v << 1) + 1], t[(v << 1) + 2]);
}

int get(int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 0;
    if(L==l && r==R)
        return t[v];

    int m = ((l + r) >> 1);

    return gcd(get((v << 1) + 1, l, m, L, min(m, R)), get((v << 1) + 2, m, r, max(L, m), R));
}

void update(int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        t[v] = val;
        return;
    }

    int m = ((l + r) >> 1);
    if(pos < m)
        update((v << 1) + 1, l, m, pos, val);
    else update((v << 1) + 2, m, r, pos, val);

    t[v] = gcd(t[(v << 1) + 1], t[(v << 1) + 2]);
}

void find(int v, int l, int r, int L, int R, int x)
{
    if(L >= R || t[v] == 0)
        return;


        if(p >= l - 1  && t[v] % x == 0)
        {
            p = r - 1;
            //cout << t[v] << ' ' << p << endl;
            return;
        }

    int m = ((l + r) >> 1);

    if(p >= l - 1)
        find((v << 1) + 1, l, m, L, min(R, m), x);
    if(p >= m - 1)
        find((v << 1) + 2, m, r, max(L, m), R, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    build(0, 0, n);

    int q;
    cin >> q;

    while(q--)
    {
        int t, l, r;
        cin >> t >> l >> r;

        if(t==1)
        {
            int x;
            cin >> x;

            p = l - 2;
            find(0, 0, n, l - 1, r, x);

            //cout << p << ' ';

            if(get(0, 0, n, p + 2, r) % x == 0)
                cout << "YES";
            else cout << "NO";

            cout << "\n";
        }
        else
        {
            update(0, 0, n, l - 1, r);
        }
    }
}