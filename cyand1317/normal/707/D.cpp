#include <cstdio>
#include <vector>
static const int MAXN = 1e3 + 3;
static const int MAXQ = 1e5 + 3;
typedef std::vector<int> childlist;

int n, m, q;
int op[MAXQ], arg1[MAXQ], arg2[MAXQ];
childlist e[MAXQ];
int ans[MAXQ];

bool g[MAXN][MAXN] = {{ false }};

void dfs(int u, int cur_ans = 0)
{
    bool b;
    switch (op[u]) {
        case 1: case 2:
            b = g[arg1[u]][arg2[u]];
            g[arg1[u]][arg2[u]] = (op[u] == 1);
            ans[u] = cur_ans - b + (op[u] == 1);
            for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i)
                dfs(*i, ans[u]);
            g[arg1[u]][arg2[u]] = b;
            break;
        case 3:
            ans[u] = cur_ans;
            for (int i = 0; i < m; ++i) {
                ans[u] += (g[arg1[u]][i] ? -1 : +1);
                g[arg1[u]][i] ^= 1;
            }
            for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i)
                dfs(*i, ans[u]);
            for (int i = 0; i < m; ++i)
                g[arg1[u]][i] ^= 1;
            break;
        case 4:
            ans[u] = cur_ans;
            for (childlist::iterator i = e[u].begin(); i != e[u].end(); ++i)
                dfs(*i, ans[u]);
            break;
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= q; ++i) {
        scanf("%d%d", &op[i], &arg1[i]);
        if (op[i] == 1 || op[i] == 2) {
            scanf("%d", &arg2[i]);
            --arg1[i]; --arg2[i];
        } else if (op[i] == 3) {
            --arg1[i];
        }
    }

    int parent;
    for (int i = 1; i <= q; ++i) {
        parent = (op[i] == 4 ? arg1[i] : i - 1);
        e[parent].push_back(i);
    }

    op[0] = 4;
    dfs(0);
    for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);

    return 0;
}