#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= M)
    {
        return a - M;
    }
    if (a < 0)
    {
        return a + M;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % M;
}

struct T
{
    int mn_x;
    int mx_x;
    int mn_y;
    int mx_y;
};

const int INF = (int) 1e9;

T operator + (T a, T b)
{
    return {min(a.mn_x, b.mn_x), max(a.mx_x, b.mx_x), min(a.mn_y, b.mn_y), max(a.mx_y, b.mx_y)};
}


const int N = (int) 5e5 + 7;
int len;
int n;
int m;
int x;
int y;
int xmin;
int xmax;
int ymin;
int ymax;
int sol;
int p;
string s;
int sumx[N];
int sumy[N];
const int K = 19;
T t[K][N];
int lg[N];
int totx;
int toty;

T get(int l, int r) /// [1...2 * len]
{
    if (r <= len)
    {
        int k = lg[r - l + 1];
        return t[k][l] + t[k][r - (1 << k) + 1];
    }
    if (l > len)
    {
        l -= len;
        r -= len;
        int k = lg[r - l + 1];
        T it = t[k][l] + t[k][r - (1 << k) + 1];
        it.mn_x += totx;
        it.mx_x += totx;
        it.mn_y += toty;
        it.mx_y += toty;
        return it;
    }
    return get(l, len) + get(len + 1, r);
}

int pnext(int p)
{
    int pos = INF, l = p, r = 2 * len - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        auto it = get(p + 1, m + 1);
        if (x - sumx[p] + it.mx_x > xmax || x - sumx[p] + it.mn_x < xmin || y - sumy[p] + it.mx_y > ymax || y - sumy[p] + it.mn_y < ymin)
        {
            pos = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    if (pos == INF)
    {
        cout << "-1\n";
        exit(0);
    }
    return pos;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

///    freopen ("input", "r", stdin);

    cin >> len >> n >> m >> s;
    s += s;
    for (int i = 2; i <= len; i++)
    {
        lg[i] = 1 + lg[i / 2];
    }
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'L')
        {
            y--;
        }
        if (s[i] == 'R')
        {
            y++;
        }
        if (s[i] == 'U')
        {
            x--;
        }
        if (s[i] == 'D')
        {
            x++;
        }
        sumx[i + 1] = x;
        sumy[i + 1] = y;
    }
    totx = x;
    toty = y;
    for (int i = 1; i <= len; i++)
    {
        t[0][i] = {sumx[i], sumx[i], sumy[i], sumy[i]};
    }
    for (int k = 1; (1 << k) <= len; k++)
    {
        for (int i = 1; i + (1 << k) - 1 <= len; i++)
        {
            t[k][i] = t[k - 1][i] + t[k - 1][i + (1 << (k - 1))];
        }
    }
    x = 0;
    y = 0;
    while (n + xmin - xmax > 0 && m + ymin - ymax > 0)
    {
        int p2 = pnext(p);
        sol = add(sol, mul(mul(n + xmin - xmax, m + ymin - ymax), p2 - p + 1));
        if (p2 < len)
        {
            x += sumx[p2 + 1] - sumx[p];
            y += sumy[p2 + 1] - sumy[p];
        }
        else
        {
            x += totx + sumx[p2 + 1 - len] - sumx[p];
            y += toty + sumy[p2 + 1 - len] - sumy[p];
        }
        xmin = min(xmin, x);
        xmax = max(xmax, x);
        ymin = min(ymin, y);
        ymax = max(ymax, y);
        p = (p2 + 1) % len;
    }
    cout << sol << "\n";
}