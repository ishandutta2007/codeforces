// Exhausting... ( )
#include <cstdio>
static const int MAXN = 200004;
static const int MAXM = 400003 * 2;
static const int TAG_EMPTY = 0;
static const int TAG_DEPRECATED = 1;
static const int TAG_SPANNING = 2;

int n, m, s, t, ds, dt;
int head[MAXN], dest[MAXM], next[MAXM], tag[MAXM];
bool vis[MAXN] = { false };
int cc_ct = 0;
int cc_id[MAXN];
bool cc_tos[MAXN] = { false }, cc_tot[MAXN] = { false };
int cc_lnk[MAXN] = { false };

inline void add_edge(int u, int v, int t = TAG_EMPTY) {
    static int w = 0;
    dest[w] = v; next[w] = head[u]; tag[w] = t; head[u] = w++;
}

void dfs_cc(int u)
{
    vis[u] = true;
    cc_id[u] = cc_ct;
    for (int w = head[u]; w != -1; w = next[w])
        if (tag[w] != TAG_DEPRECATED && !vis[dest[w]]) {
            tag[w] = TAG_SPANNING;
            dfs_cc(dest[w]);
        }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v, tg;
    bool has_edge_st = false;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        tg = TAG_EMPTY;
        add_edge(u, v, tg);
        add_edge(v, u, tg);
    }
    scanf("%d%d%d%d", &s, &t, &ds, &dt); --s, --t;
    for (int w = head[s]; w != -1; w = next[w]) tag[w] = TAG_DEPRECATED;
    for (int w = head[t]; w != -1; w = next[w]) {
        tag[w] = TAG_DEPRECATED;
        if (dest[w] == s) has_edge_st = true;
    }
    for (int i = 0; i < m * 2; ++i)
        if (dest[i] == s || dest[i] == t) tag[i] = TAG_DEPRECATED;

    cc_id[s] = cc_id[t] = -1;
    for (int i = 0; i < n; ++i) if (i != s && i != t && !vis[i]) {
        dfs_cc(i); ++cc_ct;
    }
    for (int w = head[s]; w != -1; w = next[w])
        if (dest[w] != t) cc_tos[cc_id[dest[w]]] = true;
    for (int w = head[t]; w != -1; w = next[w])
        if (dest[w] != s) cc_tot[cc_id[dest[w]]] = true;
    int tos_ct = 0, tot_ct = 0, tost_ct = 0;
    for (int i = 0; i < cc_ct; ++i) switch ((cc_tos[i] << 1) | cc_tot[i]) {
        case 0: puts("No"); return 0;
        case 1: ++tot_ct; break;
        case 2: ++tos_ct; break;
        case 3: ++tost_ct; break;
    }
    if (tot_ct > dt || tos_ct > ds || cc_ct >= (int)has_edge_st + ds + dt || (int)has_edge_st + tost_ct == 0) {
        puts("No"); return 0;
    }
    for (int i = 0; i < cc_ct; ++i) switch ((cc_tos[i] << 1) | cc_tot[i]) {
        case 1: cc_lnk[i] = 1; if (--dt < 0) { puts("No"); return 0; } break;
        case 2: cc_lnk[i] = 2; if (--ds < 0) { puts("No"); return 0; } break;
        case 3: break;
        default: return 87665544;
    }
    for (int i = 0; i < cc_ct; ++i) switch ((cc_tos[i] << 1) | cc_tot[i]) {
        case 3:
            if (ds > 0) { cc_lnk[i] = 2, --ds; }
            else { cc_lnk[i] = 1; if (--dt < 0) { puts("No"); return 0; } }
            break;
    }
    bool connected = false;
    for (int i = 0; i < cc_ct; ++i) if (cc_tos[i] && cc_tot[i]) {
        if (cc_lnk[i] == 1) --ds; else --dt;
        cc_lnk[i] = 3; connected = true; break;
    }
    if (ds < 0 || dt < 0) { puts("No"); return 0; }
    if (!connected) {
        if (!has_edge_st || ds == 0 || dt == 0) { puts("No"); return 0; }
    }
    puts("Yes");
    if (!connected) printf("%d %d\n", s + 1, t + 1);
    for (int w = head[s]; w != -1; w = next[w])
        if (cc_lnk[cc_id[dest[w]]] & 2) { tag[w] = TAG_SPANNING; cc_lnk[cc_id[dest[w]]] ^= 2; }
    for (int w = head[t]; w != -1; w = next[w])
        if (cc_lnk[cc_id[dest[w]]] & 1) { tag[w] = TAG_SPANNING; cc_lnk[cc_id[dest[w]]] ^= 1; }
    for (int i = 0; i < n; ++i)
        for (int w = head[i]; w != -1; w = next[w])
            if (tag[w] == TAG_SPANNING) printf("%d %d\n", i + 1, dest[w] + 1);

    return 0;
}