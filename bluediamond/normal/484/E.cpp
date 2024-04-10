#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int a[N];
int q;
int l[N];
int r[N];
int w[N];
int lo[N];
int hi[N];
int ans[N];
int id[N];

bool cmp_id(int i, int j)
{
    return a[i] > a[j];
}

struct Data
{
    int len;
    int res;
    int prefix;
    int sufix;
};

Data joint(Data a, Data b)
{
    if (a.res == -1)
    {
        return b;
    }
    if (b.res == -1)
    {
        return a;
    }
    int len = a.len + b.len;
    int res = max(a.sufix + b.prefix, max(a.res, b.res));
    int prefix = a.prefix + b.prefix * (a.prefix == a.len);
    int sufix = b.sufix + a.sufix * (b.sufix == b.len);
    return {len, res, prefix, sufix};
}

Data aint[4 * N];
int biggest;

void build(int v, int tl, int tr)
{
    biggest = max(biggest, v);
    aint[v].len = tr - tl + 1;
    if (tl < tr)
    {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
    }
}

void clr()
{
    for (int i = 1; i <= biggest; i++)
    {
        aint[i].res = aint[i].prefix = aint[i].sufix = 0;
    }
}

void make(int v, int tl, int tr, int p)
{
    if (tr < p || p < tl)
    {
        return;
    }
    if (tl == tr)
    {
        aint[v].res = aint[v].prefix = aint[v].sufix = 1;
    }
    else
    {
        int tm = (tl + tr) / 2;
        make(2 * v, tl, tm, p);
        make(2 * v + 1, tm + 1, tr, p);
        aint[v] = joint(aint[2 * v], aint[2 * v + 1]);
    }
}

Data get(int v, int tl, int tr, int l, int r)
{
    if (tr < l || r < tl)
    {
        return {-1, 0, 0, 0};
    }
    if (l <= tl && tr <= r)
    {
        return aint[v];
    }
    else
    {
        int tm = (tl + tr) / 2;
        return joint(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        id[i] = i;
    }
    build(1, 1, n);
    sort(id + 1, id + n + 1, cmp_id);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> l[i] >> r[i] >> w[i];
        lo[i] = 0;
        hi[i] = (int) 1e9 + 7;
    }
    while (1)
    {
        vector<pair<int, int>> asking;
        for (int i = 1; i <= q; i++)
        {
            if (lo[i] <= hi[i])
            {
                int middle = (lo[i] + hi[i]) / 2;
                asking.push_back({middle, i});
            }
        }
        if (asking.empty())
        {
            break;
        }
        clr();
        sort(asking.rbegin(), asking.rend());
        int curp = 1;
        for (auto &it : asking)
        {
            int val = it.first;
            while (curp <= n && a[id[curp]] >= val)
            {
                make(1, 1, n, id[curp]);
                curp++;
            }
            int i = it.second;
            if (get(1, 1, n, l[i], r[i]).res >= w[i])
            {
                ans[i] = val;
                lo[i] = val + 1;
            }
            else
            {
                hi[i] = val - 1;
            }
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << "\n";
    }
}