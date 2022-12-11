#include <cstdio>
#include <vector>
static const int MAXN = 100005;
typedef std::vector<int> edgelist;

int n, m;
edgelist e[MAXN];
unsigned char state[MAXN] = { 0 };
int state1_ct = 0, state2_ct = 0;

bool feasible = true;
void dfs(int u, int p = -1, int c = 1)
{
    state[u] = c;
    if (c == 1) ++state1_ct; else ++state2_ct;
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (*i != p) {
        if (state[*i] == 0) {
            dfs(*i, u, 3 - c);
            if (!feasible) return;
        } else if (state[*i] != 3 - c) {
            feasible = false; return;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) if (state[i] == 0) {
        dfs(i);
        if (!feasible) break;
    }
    if (feasible) {
        printf("%d\n", state1_ct);
        for (int i = 0; i < n; ++i) if (state[i] == 1) printf("%d ", i + 1);
        printf("\n%d\n", state2_ct);
        for (int i = 0; i < n; ++i) if (state[i] == 2) printf("%d ", i + 1);
        putchar('\n');
    } else puts("-1");
    return 0;
}