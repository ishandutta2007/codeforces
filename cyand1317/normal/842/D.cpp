#include <cstdio>
#include <algorithm>
static const int MAXN = 3e5 + 4;
static const int LOGA = 20;

int n, m;
int a[MAXN];

namespace trie {

struct node {
    int ch[2];
    int sum;
} t[MAXN * LOGA * 3];

int sz = 0;

inline void init() {
    for (int i = 0; i < (sizeof t / sizeof t[0]); ++i) {
        t[i].ch[0] = t[i].ch[1] = -1;
        t[i].sum = 0;
    }
    sz++;
}

inline void insert(int val) {
    int u = 0;
    for (int i = LOGA - 1; i >= 0; --i) {
        int &v = t[u].ch[(val >> i) & 1];
        if (v == -1) v = sz++;
        u = v;
        t[u].sum += 1;
    }
}

inline int query_mex(int oxo) {
    int u = 0, ans = 0;
    for (int i = LOGA - 1; i >= 0; --i) {
        int b = (oxo >> i) & 1;
        if (t[u].ch[b] != -1 && t[t[u].ch[b]].sum >= (1 << i)) {
            u = t[u].ch[b ^ 1];
            ans = (ans << 1) | 1;
        } else {
            u = t[u].ch[b];
            ans = (ans << 1);
        }
        if (u == -1) { ans <<= i; break; }
    }
    return ans;
}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    std::sort(a, a + n);
    n = std::unique(a, a + n) - &a[0];

    trie::init();
    for (int i = 0; i < n; ++i) trie::insert(a[i]);

    int oxo = 0, x;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &x);
        oxo ^= x;
        printf("%d\n", trie::query_mex(oxo));
    }

    return 0;
}