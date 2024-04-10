#include <cstdio>
static const int MAXQ = 200007;
static const int LOGX = 32;

namespace trie {

struct trie_node {
    int child[2];
    int ct;
} t[MAXQ * LOGX];
int sz = 0;

inline int newnode() {
    t[sz].child[0] = t[sz].child[1] = -1;
    t[sz].ct = 0;
    return sz++;
}

int root = newnode();

inline void increment(int x, int inc = +1) {
    int idx = root;
    for (int i = LOGX - 1; i >= 0; --i) {
        int &nxt = t[idx].child[(x >> i) & 1];
        if (nxt == -1) nxt = newnode();
        idx = nxt;
        t[idx].ct += inc;
    }
}

inline int query(int x) {
    int idx = root;
    int ans = 0;
    for (int i = LOGX - 1; i >= 0; --i) {
        int nxt = t[idx].child[((x >> i) & 1) ^ 1];
        //ans = (ans << 1) | (((x >> i) & 1) ^ 1);
        ans = (ans << 1) | 1;
        if (nxt == -1 || t[nxt].ct == 0) {
            nxt = t[idx].child[(x >> i) & 1];
            ans ^= 1;
        }
        idx = nxt;
    }
    return ans;
}

}

int q;

int main()
{
    scanf("%d", &q);
    trie::increment(0, +1);

    char op;
    int arg;
    do {
        getchar();
        scanf("%c%d", &op, &arg);
        switch (op) {
            case '+': trie::increment(arg, +1); break;
            case '-': trie::increment(arg, -1); break;
            case '?': printf("%d\n", trie::query(arg)); break;
        }
    } while (--q);

    return 0;
}