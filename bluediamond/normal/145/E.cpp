#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;

int n, q;
int v[N];

int f4[4 * N];
int f7[4 * N];
int a[4 * N];
int b[4 * N];

void calculate(int nod)
{
        f4[nod] = f4[2 * nod] + f4[2 * nod + 1];
        f7[nod] = f7[2 * nod] + f7[2 * nod + 1];
        a[nod] = max(f4[2 * nod] + a[2 * nod + 1], a[2 * nod] + f7[2 * nod + 1]);
        b[nod] = max(f7[2 * nod] + b[2 * nod + 1], b[2 * nod] + f4[2 * nod + 1]);
}

void build(int nod, int tl, int tr)
{
        if(tl == tr)
        {
                f4[nod] = (v[tl] == 4);
                f7[nod] = (v[tl] == 7);
                a[nod] = 1;
                b[nod] = 1;
        }
        else
        {
                int tm = (tl + tr) >> 1;
                build(2 * nod, tl, tm);
                build(2 * nod + 1, tm + 1, tr);
                calculate(nod);
        }
}

bool Lazy[4 * N];

bool inverse(bool a)
{
        if(a == 0)
        {
                return 1;
        }
        else
        {
                return 0;
        }
}

void push(int nod)
{
        if(Lazy[nod])
        {
                Lazy[nod] = 0;
                if(2 * nod < 4 * N)
                {
                        Lazy[2 * nod] = inverse(Lazy[2 * nod]);
                }
                if(2 * nod + 1 < 4 * N)
                {
                        Lazy[2 * nod + 1] = inverse(Lazy[2 * nod + 1]);
                }
                swap(f4[nod], f7[nod]);
                swap(a[nod], b[nod]);
        }
}

void change(int nod, int tl, int tr, int l, int r)
{
        if(tr < l || r < tl)
        {
                return;
        }
        if(l <= tl && tr <= r)
        {
                Lazy[nod] = inverse(Lazy[nod]);
                push(nod);
        }
        else
        {
                push(nod);
                int tm = (tl + tr) >> 1;
                change(2 * nod, tl, tm, l, r);
                change(2 * nod + 1, tm + 1, tr, l, r);
                push(2 * nod);
                push(2 * nod + 1);
                calculate(nod);
        }
}

int get()
{
        push(1);
        return a[1];
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        cin >> n >> q;
        string s;
        cin >> s;
        for(int i = 1; i <= n; i++)
        {
                v[i] = (s[i - 1] - '0');
        }
        build(1, 1, n);
        while(q--)
        {
                string s;
                cin >> s;
                if(s == "count")
                {
                        cout << get() << "\n";
                }
                else
                {
                        int l, r;
                        cin >> l >> r;
                        change(1, 1, n, l, r);
                }
        }
}