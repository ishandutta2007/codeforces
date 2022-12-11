#include <cstdio>
#include <cstring>
#include <vector>
static const int MAXN = 200006;
typedef std::vector<int> edgelist;

int n;
int a[MAXN], b[MAXN];
edgelist e[MAXN];

int cc_ct = 0;
int vis[MAXN] = { 0 };
int cc_id[MAXN];
bool on_cycle[MAXN] = { false };
int dfs_route[MAXN] = { 0 };
// This is not necessarily a CC but whatever... _>
void dfs_traverse(int u, int d = 0)
{
    vis[u] = 1;
    cc_id[u] = cc_ct;
    dfs_route[d] = u;
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i)
        if (vis[*i] == 0) dfs_traverse(*i, d + 1);
        else if (vis[*i] == 1) {
            //printf("Cycle: %d -> %d\n", u, *i);
            for (int j = d; dfs_route[j] != *i; --j)
                on_cycle[dfs_route[j]] = true;
            on_cycle[*i] = true;
        }
    vis[u] = 2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); --a[i];
        b[i] = a[i];
        e[a[i]].push_back(i);
    }

    for (int i = 0; i < n; ++i) if (!vis[i]) {
        dfs_traverse(i);
        ++cc_ct;
    }
    //for (int i = 0; i < n; ++i) printf("%d %d\n", cc_id[i], on_cycle[i]);

    int rt = -1;
    int moves = 0;
    for (int i = 0; i < n; ++i) if (a[i] == i) { rt = i; break; }
    if (rt == -1) {
        for (int i = 0; i < n; ++i) if (on_cycle[i]) {
            b[i] = i; ++moves;
            rt = i; break;
        }
    }
    memset(vis, false, sizeof vis);
    vis[cc_id[rt]] = true;
    //printf("root = %d\n", rt);
    for (int i = 0; i < n; ++i) {
        if (on_cycle[i] && !vis[cc_id[i]]) {
            b[i] = rt; ++moves;
            vis[cc_id[i]] = true;
        }
    }

    printf("%d\n", moves);
    for (int i = 0; i < n; ++i)
        printf("%d%c", b[i] + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}