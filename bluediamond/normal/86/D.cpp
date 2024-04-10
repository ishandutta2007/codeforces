#include <bits/stdc++.h>.

using namespace std;

typedef long long ll;

const int N = 200000 + 7;
const int L = 1000000 + 7;

int n, q, a[N];
int block;

struct Q
{
        int l;
        int r;
        int i;
};

bool operator < (Q a, Q b)
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

int f[L];

ll func(int i)
{
        return f[i] * (ll) f[i] * (ll) i;
}

ll cur;

void add(int i, int x)
{
        i = a[i];
        cur -= func(i);
        f[i] += x;
        cur += func(i);
}

int l, r;

Q b[N];
ll sol[N];

void bring_l(int to)
{
        while (l < to && l < r)
        {
                add(l, -1);
                l++;
        }
        while (to < l)
        {
                l--;
                add(l, +1);
        }
}

void bring_r(int to)
{
        while (r < to)
        {
                r++;
                add(r, +1);
        }
        while (to < r && r > l)
        {
                add(r, -1);
                r--;
        }
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;
        block = sqrt(n);

        for (int i = 0; i < n; i++)
        {
                cin >> a[i];
        }

        for (int i = 0; i < q; i++)
        {
                cin >> b[i].l >> b[i].r;
                b[i].l--;
                b[i].r--;
                b[i].i = i;
        }

        sort(b, b + q);
        l = 0;
        r = 0;
        add(0, +1);

        for (int i = 0; i < q; i++)
        {
                bring_l(b[i].l);
                bring_r(b[i].r);
                bring_l(b[i].l);

                sol[b[i].i] = cur;

        }

        for (int i = 0; i < q; i++)
        {
                cout << sol[i] << "\n";
        }

}