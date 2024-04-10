#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n;
string str;
int init[N];
int mn[4 * N];
int mx[4 * N];
int lazy[4 * N];

void push(int v, int tl, int tr)
{
    if (lazy[v])
    {
        mn[v] += lazy[v];
        mx[v] += lazy[v];
        if (tl  < tr)
        {
            lazy[2 * v] += lazy[v];
            lazy[2 * v + 1] += lazy[v];
        }
        lazy[v] = 0;
    }
}

void add(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        lazy[v] += x;
        push(v, tl, tr);
    }
    else
    {
        int tm = (tl + tr) / 2;
        add(2 * v, tl, tm, l, r, x);
        add(2 * v + 1, tm + 1, tr, l, r, x);
        mn[v] = min(mn[2 * v], mn[2 * v + 1]);
        mx[v] = max(mx[2 * v], mx[2 * v + 1]);
    }
}

int g_mn()
{
    push(1, 1, n);
    return mn[1];
}

int g_mx()
{
    push(1, 1, n);
    return mx[1];
}

int sum;

void upd(int i, int x)
{
    x -= init[i];
    add(1, 1, n, i, n, x);
    init[i] += x;
    sum += x;
}

int get()
{
    if (sum == 0 && g_mn() == 0)
    {
        return g_mx();
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> str;
    int ptr = 1;
    for (auto &x : str)
    {
        if (x == 'L')
        {
            ptr--;
            ptr += (!ptr);
        }
        if (x == 'R')
        {
            ptr++;
        }
        if (x == '(')
        {
            upd(ptr, +1);
        }
        if (x == ')')
        {
            upd(ptr, -1);
        }
        if ('a' <= x && x <= 'z')
        {
            upd(ptr, 0);
        }
        cout << get() << " ";
    }
    cout << "\n";

}