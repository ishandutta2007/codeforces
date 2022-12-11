#include <cstdio>
#include <cstring>
#include <queue>
static const int MAXN = 5004;

namespace sam {

static const int MAXN = ::MAXN * 2;
static const int ALPHABET = 26;
int sz, last;
int len[MAXN], par[MAXN], trans[MAXN][ALPHABET];
int endsets[MAXN];

inline void init() {
    sz = 1, last = 0;
    len[0] = 0, par[0] = -1;
    memset(trans, -1, sizeof trans);
}

inline void extend(char token) {
    int nw = sz++, p = last;
    len[nw] = len[last] + 1; endsets[nw] = 1;
    for (; p != -1 && trans[p][token] == -1; p = par[p]) trans[p][token] = nw;
    if (p == -1) {
        par[nw] = 0;
    } else {
        int q = trans[p][token];
        if (len[p] + 1 == len[q]) {
            par[nw] = q;
        } else {
            int r = sz++; len[r] = len[p] + 1; endsets[r] = 0;
            memcpy(trans[r], trans[q], sizeof trans[r]);
            par[r] = par[q];
            par[q] = par[nw] = r;
            for (; p != -1 && trans[p][token] == q; p = par[p]) trans[p][token] = r;
        }
    }
    last = nw;
}

int shortest[MAXN];
int matches[MAXN] = { 0 };
int in_deg[MAXN];
inline void calc_endsets() {
    memset(in_deg, 0, sizeof in_deg);

    for (int i = 0; i < sz; ++i) if (par[i] != -1) ++in_deg[par[i]];
    std::queue<int> q;
    for (int i = 0; i < sz; ++i) if (in_deg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        endsets[par[u]] += endsets[u];
        matches[par[u]] += matches[u];
        if (--in_deg[par[u]] == 0) q.push(par[u]);
    }

    for (int i = 0; i < sz; ++i) shortest[i] = (par[i] == -1 ? 0 : len[par[i]] + 1);

    /*for (int i = 0; i < sz; ++i) {
        printf("%d(%d/%d) |", i, endsets[i], matches[i]);
        for (int j = 0; j < ALPHABET; ++j)
            if (trans[i][j] != -1) printf(" %c%d", 'a' + j, trans[i][j]);
        putchar('\n');
    }*/
}

}

int n, m;
char s[MAXN], t[MAXN];

int main()
{
    gets(s); n = strlen(s);
    gets(t); m = strlen(t);

    sam::init();
    for (int i = 0; i < n; ++i) sam::extend(s[i] - 'a');

    // Feed t into the automaton
    int u = 0;
    for (int i = 0; i < m; ++i) {
        while (u != 0 && sam::trans[u][t[i] - 'a'] == -1) u = sam::par[u];
        if (sam::trans[u][t[i] - 'a'] != -1) u = sam::trans[u][t[i] - 'a'];
        sam::matches[u]++;
    }

    sam::calc_endsets();
    int ans = MAXN;
    for (int i = 1; i < sam::sz; ++i) {
        if (sam::endsets[i] == 1 && sam::matches[i] == 1)
            if (ans > sam::shortest[i]) ans = sam::shortest[i];
    }

    printf("%d\n", ans == MAXN ? -1 : ans);
    return 0;
}