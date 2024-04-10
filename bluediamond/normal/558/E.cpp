#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e5 + 7;

struct segt
{
        int lazy[4 * N];
        int ret[4 * N];
        bool blocked[4 * N];

        void init()
        {
                for(int i = 0; i < 4 * N; i++)
                {
                        lazy[i] = ret[i] = 0;
                }
        }

        void push(int nod, int tl, int tr)
        {
                if(blocked[nod])
                {
                        blocked[2 * nod] = 1;
                        blocked[2 * nod + 1] = 1;
                        lazy[2 * nod] = 0;
                        lazy[2 * nod + 1] = 0;
                        ret[2 * nod] = 0;
                        ret[2 * nod + 1] = 0;
                        blocked[nod] = 0;
                        ///  return;
                }
                int tm = (tl + tr) >> 1;
                int l1 = (tm - tl + 1);
                int l2 = (tr - tl + 1) - l1;
                int t = lazy[nod];
                lazy[nod] = 0;
                lazy[2 * nod] += t;
                lazy[2 * nod + 1] += t;
                ret[2 * nod] += t * l1;
                ret[2 * nod + 1] += t * l2;
        }

        void upd(int nod, int tl, int tr, int l, int r, int x)
        {
                if(tr < l || r < tl)
                {
                        return;
                }
                if(l <= tl && tr <= r)
                {
                        lazy[nod] += x;
                        ret[nod] += x * (tr - tl + 1);
                }
                else
                {
                        push(nod, tl, tr);
                        int tm = (tl + tr) >> 1;
                        upd(2 * nod, tl, tm, l, r, x);
                        upd(2 * nod + 1, tm + 1, tr, l, r, x);
                        ret[nod] = ret[2 * nod] + ret[2 * nod + 1];
                }
                /// if(tr>=3) return;
                /// cout<<" ---> "<<tl<<","<<tr<<" : "<<ret[nod]<<" and "<<lazy[nod]<<" , "<<blocked[nod]<<"\n";
        }

        void del(int nod, int tl, int tr, int l, int r)
        {
                if(tr < l || r < tl)
                {
                        return;
                }
                if(l <= tl && tr <= r)
                {
                        blocked[nod] = 1;
                        lazy[nod] = 0;
                        ret[nod] = 0;
                }
                else
                {
                        push(nod, tl, tr);
                        int tm = (tl + tr) >> 1;
                        del(2 * nod, tl, tm, l, r);
                        del(2 * nod + 1, tm + 1, tr, l, r);
                        ret[nod] = ret[2 * nod] + ret[2 * nod + 1];
                }
        }

        int get(int nod, int tl, int tr, int l, int r)
        {
                if(tr < l || r < tl)
                {
                        return 0;
                }
                if(l <= tl && tr <= r)
                {
                        return ret[nod];
                }
                else
                {
                        push(nod, tl, tr);
                        int tm = (tl + tr) >> 1;
                        return get(2 * nod, tl, tm, l, r) + get(2 * nod + 1, tm + 1, tr, l, r);
                }
        }
};

int n, q;
int v[N];
segt t[26];

int f[26];

void print()
{
        for(int i = 1; i <= n; i++)
        {
                bool g = 0;
                for(int j = 0; j < 26; j++)
                {
                        if(t[j].get(1, 1, n, i, i) > 0)
                        {
                                g = 1;
                                cout << char(j + 'a');
                        }
                }
                if(g == 0)
                {
                        cout << "?";
                }
        }
        cout << "\n";
}

int main()
{
        ios::sync_with_stdio(false);
        cin.tie(0);
        for(int i = 0; i < 26; i++)
        {
                t[i].init();
        }
        cin >> n >> q;
        string st;
        cin >> st;
        for(int i = 1; i <= n; i++)
        {
                v[i] = st[i - 1] - 'a';
                t[v[i]].upd(1, 1, n, i, i, 1);
        }
        while(q--)
        {
                int l, r, k;
                cin >> l >> r >> k;
                for(int i = 0; i < 26; i++)
                {
                        f[i] = 0;
                }
                for(int i = 0; i < 26; i++)
                {
                        f[i] = t[i].get(1, 1, n, l, r);
                }
                for(int i = 0; i < 26; i++)
                {
                        t[i].del(1, 1, n, l, r);
                }
                int p = l;
                if(k == 1)
                {
                        for(int j = 0; j < 26; j++)
                        {
                                if(f[j] == 0) continue;
                                t[j].upd(1, 1, n, p, p + f[j] - 1, 1);
                                p += f[j];
                        }
                }
                else
                {
                        for(int j = 25; j >= 0; j--)
                        {
                                if(f[j] == 0) continue;
                                t[j].upd(1, 1, n, p, p + f[j] - 1, 1);
                                p += f[j];
                        }
                }
        }
        print();
}