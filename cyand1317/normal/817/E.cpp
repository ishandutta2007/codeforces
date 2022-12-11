#include <cstdio>
static const int MAXQ = 1e5 + 4;
static const int LOGP = 27;

int q;

namespace trie {

static const int MAXN = ::MAXQ * ::LOGP;
int sz = 1;
struct node {
    int val, ch[2];
    node() { ch[0] = ch[1] = -1; }
} t[MAXN];

inline void add(int x, int inc) {
    int u = 0;
    for (int i = LOGP - 1; i >= 0; --i) {
        int &v = t[u].ch[(x >> i) & 1];
        if (v == -1) v = sz++;
        u = v;
        t[u].val += inc;
    }
}

inline int query(int x, int l) {
    int u = 0, ans = 0;
    for (int i = LOGP - 1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        int v = t[u].ch[bit], w = t[u].ch[bit ^ 1];
        if ((l >> i) & 1) {
            if (v != -1) ans += t[v].val;
            u = w;
        } else {
            u = v;
        }
        if (u == -1) break;
    }
    return ans;
}

}

int main()
{
    scanf("%d", &q);

    int op, p, l;
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &op, &p);
        switch (op) {
            case 1: trie::add(p, +1); break;
            case 2: trie::add(p, -1); break;
            case 3:
                scanf("%d", &l);
                printf("%d\n", trie::query(p, l)); break;
            default: puts("> <");
        }
    }

    return 0;
}