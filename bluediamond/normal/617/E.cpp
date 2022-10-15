#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 7;
int n, m, k;
int tab[N];

struct Mo
{
        int l;
        int r;
        int i;
};

int bucketS;

bool operator < (Mo a, Mo b)
{
        if (a.l / bucketS == b.l / bucketS)
                return a.r < b.r;
        return a.l < b.l;
}

Mo q[N];

int L, R;
ll cur = 0;

int f[20 * N];

void add(int x)
{
        x = tab[x];
        if (k == 0)
                cur -= f[x] * (ll) (f[x] - 1) / 2;
        else
                cur -= f[x] * (ll) f[x ^ k];
        f[x]++;
        if (k == 0)
                cur += f[x] * (ll) (f[x] - 1) / 2;
        else
                cur += f[x] * (ll) f[x ^ k];
}

void del(int x)
{
        x = tab[x];
        if (k == 0)
                cur -= f[x] * (ll) (f[x] - 1) / 2;
        else
                cur -= f[x] * (ll) f[x ^ k];
        f[x]--;
        if (k == 0)
                cur += f[x] * (ll) (f[x] - 1) / 2;
        else
                cur += f[x] * (ll) f[x ^ k];
}

void bring_l(int l)
{
        while (L < l && L < R)
                del(L++);
        while (l < L)
                add(--L);
}

void bring_r(int r)
{
        while (R < r)
                add(++R);
        while (r < R && L < R)
                del(R--);
}

void bring(int l, int r)
{
        bring_l(l);
        bring_r(r);
        bring_l(l);
}

ll ans[N];

int main()
{
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
                scanf("%d", &tab[i]);
                tab[i] ^= tab[i - 1];
        }
        bucketS = sqrt(m);
        for (int i = 1; i <= m; i++)
        {
                scanf("%d %d", &q[i].l, &q[i].r);
                q[i].l--;
                q[i].i = i;
        }
        sort(q + 1, q + m + 1);
        add(0);
        for (int i = 1; i <= m; i++)
        {
                bring(q[i].l, q[i].r);
                ans[q[i].i] = cur;
        }
        for (int i = 1; i <= m; i++)
                printf("%I64d\n", ans[i]);
}