#include <bits/stdc++.h>

using namespace std;

const int N = 150000 + 7;

int n, len, h;
int b[N], a[N];

int tree[4 * N], lazy[4 * N];

void push(int nod)
{
        if (lazy[nod])
        {
                tree[nod] += lazy[nod];
                if (2 * nod < 4 * N)
                {
                        lazy[2 * nod] += lazy[nod];
                        if (2 * nod + 1 < 4 * N)
                        {
                                lazy[2 * nod + 1] += lazy[nod];
                        }
                }
                lazy[nod] = 0;
        }
}

void upd(int nod, int tl, int tr, int l, int r, int val)
{
        push(nod);
        if (tr < l || r < tl) return;
        if (l <= tl && tr <= r)
        {
                lazy[nod] += val;
                push(nod);
        }
        else
        {
                push(nod);
                int tm = (tl + tr) / 2;
                upd(2 * nod, tl, tm, l, r, val);
                upd(2 * nod + 1, tm + 1, tr, l, r, val);
                tree[nod] = max(tree[2 * nod], tree[2 * nod + 1]);
        }
}

void add(int l, int r, int val)
{
        upd(1, 0, len, l, r, val);
}

/**
sa nu existe
f[0] + f[1] + ... + f[x] > x
=>
pentru toate
f[0] + f[1] + ... + f[x] - x <= 0
=>
max(f[0] + ... + f[x] - x) = 0
**/

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> len >> h;
        for (int i = 1; i <= len; i++)
        {
                cin >> b[i];
        }
        sort(b + 1, b + len + 1);
        reverse(b + 1, b + len + 1);

        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                int ans = 0;
                int l = 1, r = len;
                while (l <= r)
                {
                        int m = (l + r) / 2;
                        if (b[m] >= h - x)
                        {
                                ans = m;
                                l = m + 1;
                        }
                        else
                        {
                                r = m - 1;
                        }
                }
                a[i] = ans;
        }

        for (int x = 0; x <= len; x++)
        {
                add(x, x, -x);
        }

        int ans = 0;
        for (int l = 1; l + len - 1 <= n; l++)
        {
                int r = l + len - 1;
                if (l == 1)
                {
                      //  cout << "0 : " << tree[1] << "\n";
                        for (int j = 1; j <= len; j++)
                        {
                                add(a[j], len, +1);
                             //   cout << j << " : " << tree[1] << "\n";
                        }
                }
                else
                {
                        add(a[r], len, +1);
                        add(a[l - 1], len, -1);
                }
               /** if (tree[1] == 0)
                {
                        cout << " -> " << l << " " << r << "\n";
                }**/
          //      cout << tree[1] << " ";
                ans += (tree[1] <= 0);
        }
      //  cout << "\n";
        cout << ans << "\n";

        return 0;
}