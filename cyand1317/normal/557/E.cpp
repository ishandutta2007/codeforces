// Start over. Last version uses up to ~6 secs  **:....:*'(**)'*:.. ..:**
// Start over. Last version uses hash and causes conflicts  T T
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
static const int INF = 0x7fffffff;
static const int MAXN = 5009;
typedef unsigned long long hash_t;

namespace trie {
int val[MAXN * MAXN / 2] = { 0 }, child[MAXN * MAXN / 2][2] = {{ 0 }};
int sz = 1;

inline void insert(char *s) {
    int cur = 1;
    for (; *s; ++s) {
        int &nw = child[cur][*s - 'a'];
        if (nw == 0) nw = ++sz;
        cur = nw;
    }
}
inline int move(int cur, char ch) { return child[cur][ch - 'a']; }
inline void rebuild(int u = 1) {
    if (child[u][0] != 0) rebuild(child[u][0]);
    if (child[u][1] != 0) rebuild(child[u][1]);
    val[u] += (val[child[u][0]] + val[child[u][1]]);
}
}

int n = 0, k;
char s[MAXN];
bool hpalin[MAXN][MAXN] = {{ false }};

int main()
{
    while ((s[n] = getchar()) != '\n') ++n;
    s[n] = '\0';
    scanf("%d", &k);

    for (int i = 0; i < n; ++i) {
        hpalin[i][i] = true;
        if (i > 0) hpalin[i - 1][i] = (s[i - 1] == s[i]);
        if (i > 1) hpalin[i - 2][i] = (s[i - 2] == s[i]);
        if (i > 2) hpalin[i - 3][i] = (s[i - 3] == s[i]);
    }
    for (int len = 5; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i)
            hpalin[i][i + len - 1] = (hpalin[i + 2][i + len - 3] && s[i] == s[i + len - 1]);
    }
    /*for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j) if (hpalin[i][j]) {
            for (int k = i; k <= j; ++k) putchar(s[k]); putchar('\n');
        }*/

    for (int i = 0; i < n; ++i) trie::insert(s + i);
    for (int i = 0; i < n; ++i) {
        int cur = 1;
        for (int j = i; j < n; ++j) {
            cur = trie::move(cur, s[j]);
            if (hpalin[i][j]) ++trie::val[cur];
        }
    }
    trie::rebuild();

    int cur = 1;
    while (k > 0) {
        if ((k -= (trie::val[cur] - trie::val[trie::child[cur][0]] - trie::val[trie::child[cur][1]])) <= 0) break;
        if (trie::val[trie::child[cur][0]] >= k) {
            cur = trie::child[cur][0];
            putchar('a');
        } else {
            k -= trie::val[trie::child[cur][0]];
            cur = trie::child[cur][1];
            putchar('b');
        }
    }
    putchar('\n');

    return 0;
}