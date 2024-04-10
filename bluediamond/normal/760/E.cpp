#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n;
int mx[4 * N];
int add[4 * N];

void push(int v, int tl, int tr)
{
    if (add[v])
    {
        mx[v] += add[v];
        if (tl < tr)
        {
            add[2 * v] += add[v];
            add[2 * v + 1] += add[v];
        }
        add[v] = 0;
    }
}

void upd(int v, int tl, int tr, int l, int r, int x)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return;
    }
    if (l <= tl && tr <= r)
    {
        add[v] += x;
        push(v, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, x);
    upd(2 * v + 1, tm + 1, tr, l, r, x);
    mx[v] = max(mx[2 * v], mx[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r)
{
    push(v, tl, tr);
    if (tr < l || r < tl)
    {
        return -(int) 1e9;
    }
    if (l <= tl && tr <= r)
    {
        return mx[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

int suf(int i)
{
    return get(1, 1, n, i, n);
}

int kek[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j, t;
        cin >> j >> t;
        if (t == 1)
        {
            cin >> kek[j];
            upd(1, 1, n, 1, j, +1);
        }
        else
        {
            upd(1, 1, n, 1, j, -1);
        }
        if (suf(1) <= 0)
        {
            cout << "-1\n";
        }
        else
        {
            int l = 1, r = n, ans;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (suf(mid) > 0)
                {
                    ans = mid;
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            cout << kek[ans] << "\n";
        }
    }

}