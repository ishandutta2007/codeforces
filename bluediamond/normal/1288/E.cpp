#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 3e5 + 7;
int n;
int m;
int a[N];
int x[N];
int y[N];
vector<int> p[N];
int cur[N];
int t[N];
int fs[N];

void add(int i, int x)
{
    while (i < N)
    {
        t[i] += x;
        i += i & (-i);
    }
}

int get(int i)
{
    int sol = 0;
    while (i)
    {
        sol += t[i];
        i -= i & (-i);
    }
    return sol;
}

struct question
{
    int l;
    int r;
    int v;
};

int block;
int cur_sol;

bool operator < (question a, question b)
{
    if (a.l / block == b.l / block)
    {
        return a.r < b.r;
    }
    else
    {
        return a.l < b.l;
    }
}

int cnt[N];

void ins(int i)
{
    i = a[i];
    cnt[i]++;
    cur_sol += (cnt[i] == 1);
}

void del(int i)
{
    i = a[i];
    cnt[i]--;
    cur_sol -= (cnt[i] == 0);
}

question b[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    block = sqrt(m);
    for (int i = 1; i <= n; i++)
    {
        x[i] = y[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        x[a[i]] = 1;
        p[a[i]].push_back(i);
    }
    for (int v = 1; v <= n; v++)
    {
        if ((int) p[v].size() >= 1)
        {
            add(p[v][0], 1);
        }
    }
    int q = 0;
    for (int v = 1; v <= n; v++)
    {
        if ((int) p[v].size() >= 1)
        {
            y[v] = max(y[v], v + get(p[v][0]) - 1);
            add(p[v][0], -1);
            for (int i = 0; i + 1 < (int) p[v].size(); i++)
            {
                b[++q] = {p[v][i] + 1, p[v][i + 1] - 1, v};
            }
            if (p[v].back() + 1 <= m)
            {
                b[++q] = {p[v].back() + 1, m, v};
            }
        }
        else
        {
            y[v] = max(y[v], v + get(N - 1));
        }
    }
    sort(b + 1, b + q + 1);
    int l, r;
    l = r = 1;
    ins(1);
    for (int i = 1; i <= q; i++)
    {
        while (r < b[i].r)
        {
            r++;
            ins(r);
        }
        while (r > b[i].r)
        {
            del(r);
            r--;
        }
        while (l < b[i].l)
        {
            del(l);
            l++;
        }
        while (b[i].l < l)
        {
            l--;
            ins(l);
        }
        y[b[i].v] = max(y[b[i].v], cur_sol + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << " " << y[i] << "\n";
    }
}