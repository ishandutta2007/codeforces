#include <cstdio>
#include <cstring>
typedef long long int64;
static const int MAXN = 1e5 + 4;

namespace sam {

static const int MAXN = ::MAXN * 2;
static const int ALPHABET = 26;
int sz;
int len[MAXN], par[MAXN], trans[MAXN][ALPHABET];

inline void init() { sz = 1; par[0] = -1; memset(trans, -1, sizeof trans); }

// last - index of the most recently inserted node
inline int extend(int last, char token) {
    int p = last, nw = sz++;
    len[nw] = len[last] + 1;
    for (; p != -1 && trans[p][token] == -1; p = par[p]) trans[p][token] = nw;
    if (p == -1) {
        par[nw] = 0;    // Hang below the root
    } else {
        int q = trans[p][token];
        if (len[q] == len[p] + 1) par[nw] = q;
        else {
            // Make a copy of q
            int r = sz++; par[r] = par[q]; memcpy(trans[r], trans[q], sizeof trans[r]);
            len[r] = len[p] + 1;
            par[q] = par[nw] = r;
            for (; p != -1 && trans[p][token] == q; p = par[p]) trans[p][token] = r;
        }
    }
    return nw;
}

bool is_termination[MAXN] = { false };
int64 accept_count[MAXN];
int64 substr_count[MAXN];
void dfs(int u) {
    if (accept_count[u] != -1) return;
    accept_count[u] = substr_count[u] = (is_termination[u] ? 1 : 0);
    for (int i = 0; i < ALPHABET; ++i) if (trans[u][i] != -1) {
        dfs(trans[u][i]);
        accept_count[u] += accept_count[trans[u][i]];
        substr_count[u] += accept_count[trans[u][i]] + substr_count[trans[u][i]];
    }
}
void print_substr_by_rank(int last, int rk) {
    for (int u = last; u != 0; u = par[u]) is_termination[u] = true;

    memset(accept_count, -1, sizeof accept_count);
    dfs(0);
    /*for (int i = 0; i < sz; ++i) {
        printf("%d(%d/%lld/%lld) |", i, is_termination[i], accept_count[i], substr_count[i]);
        for (int j = 0; j < ALPHABET; ++j)
            if (trans[i][j] != -1) printf(" %c%d", 'a' + j, trans[i][j]);
        putchar('\n');
    }*/

    int u = 0;
    while (rk > 0) {
        for (int i = 0; i < ALPHABET; ++i) if (trans[u][i] != -1) {
            if (rk > substr_count[trans[u][i]]) {
                rk -= substr_count[trans[u][i]];
            } else {
                rk -= accept_count[trans[u][i]];
                u = trans[u][i]; putchar('a' + i); break;
            }
        }
    }
    putchar('\n');
}

}

char s[MAXN];
int n, k;

int main()
{
    gets(s); n = strlen(s);

    sam::init();
    int last = 0;
    for (int i = 0; s[i] != '\0'; ++i) last = sam::extend(last, s[i] - 'a');

    scanf("%d", &k);
    if ((int64)n * (n + 1) / 2 < k) puts("No such line.");
    else sam::print_substr_by_rank(last, k);

    return 0;
}