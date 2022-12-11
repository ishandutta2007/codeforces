#include <cstdio>
#include <algorithm>
#include <map>
static const int MAXN = 1000005;
static const int MAXM = 1000005;

int n, m;
int a[MAXN];
int pfx_xorsum[MAXN];
int ans[MAXM];
struct query {
    int l, r, id;
} q[MAXM];
inline bool operator < (const query &lhs, const query &rhs) {
    return lhs.r < rhs.r;
}

namespace fenwick {

int f[MAXN] = { 0 };

inline void increment(int pos, int inc) {
    for (; pos < MAXN; pos += (pos & -pos)) f[pos] ^= inc;
}
inline int sum(int rg) {
    int ans = 0;
    for (; rg; rg -= (rg & -rg)) ans ^= f[rg];
    return ans;
}
inline int sum(int lf, int rg) {
    return sum(rg) ^ sum(lf - 1);
}
inline void assign(int pos, int val) {
    increment(pos, val ^ sum(pos, pos));
}

}

int main()
{
    std::map<int, int> last;

    scanf("%d", &n);
    pfx_xorsum[0] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        last[a[i]] = -1;
        pfx_xorsum[i + 1] = pfx_xorsum[i] ^ a[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &q[i].l, &q[i].r); --q[i].l, --q[i].r;
        q[i].id = i;
    }
    std::sort(q, q + m);

    int q_ptr = 0;
    for (int i = 0; i < n; ++i) {
        int &p = last[a[i]];
        if (p != -1) fenwick::assign(p, 0);
        fenwick::increment(i + 1, a[i]);
        p = i + 1;
        while (q_ptr < m && q[q_ptr].r == i) {
            ans[q[q_ptr].id] =
                fenwick::sum(q[q_ptr].l + 1, i + 1) ^
                pfx_xorsum[i + 1] ^ pfx_xorsum[q[q_ptr].l];
            ++q_ptr;
        }
    }

    for (int i = 0; i < m; ++i) printf("%d\n", ans[i]);
    return 0;
}