#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = (int) 1e9 + 7;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
    {
        return a - MOD;
    }
    if (a < 0)
    {
        return a + MOD;
    }
    return a;
}

int mul(int a, int b)
{
    return a * (ll) b % MOD;
}

int pw(int a, int b)
{
    int r = 1;
    while (b)
    {
        if (b & 1)
        {
            r = mul(r, a);
        }
        a = mul(a, a);
        b /= 2;
    }
    return r;
}

int dv(int a, int b)
{
    return mul(a, pw(b, MOD - 2));
}

const int N = (int) 1e5 + 7;
int n;
int m;
vector<pair<int, int>> hate;
int love[N];
vector<int> g[N];
int col[N];

int par(int a)
{
    if (love[a] == a)
    {
        return a;
    }
    else
    {
        return love[a] = par(love[a]);
    }
}

void rel(int a, int b)
{
    a = par(a);
    b = par(b);
    love[a] = b;
}

void color(int a)
{
    for (auto &b : g[a])
    {
        if (col[b] == 0)
        {
            col[b] = 3 - col[a];
            color(b);
        }
        else
        {
            if (col[b] == col[a])
            {
                cout << "0\n";
                exit(0);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        love[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c)
        {
            rel(a, b);
        }
        else
        {
            hate.push_back({a, b});
        }
    }
    for (auto &x : hate)
    {
        x.first = par(x.first);
        x.second = par(x.second);
        g[x.first].push_back(x.second);
        g[x.second].push_back(x.first);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (par(i) == i && col[i] == 0)
        {
            col[i] = 1;
            color(i);
            ans = mul(ans, 2);
        }
    }
    cout << dv(ans, 2) << "\n";
}