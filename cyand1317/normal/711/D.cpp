#include <cstdio>
#include <vector>
typedef std::vector<int> edgelist;
static const int MAXN = 200008;
static const int MODULUS = 1e9 + 7;

int n;
edgelist e[MAXN];
int pow2[MAXN];
bool vis[MAXN] = { false };
int dep[MAXN];
int cur_ans;
int free_edges;

void dfs(int u, int p = -1, int d = 0)
{
    vis[u] = true;
    dep[u] = d;
    bool par_vis = false;
    for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i) if (par_vis || *i != p) {
        if (vis[*i]) {
            if (dep[*i] < d) {
                cur_ans = (cur_ans + pow2[d - dep[*i] + 1] - 2) % MODULUS;
                free_edges -= (d - dep[*i] + 1);
            }
        } else {
            dfs(*i, u, d + 1);
        }
    } else {
        par_vis = true;
    }
}

int main()
{
    scanf("%d", &n);
    pow2[0] = 1;
    for (int i = 1; i < MAXN; ++i)
        pow2[i] = (pow2[i - 1] + pow2[i - 1]) % MODULUS;
    int w;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w); --w;
        e[w].push_back(i);
        e[i].push_back(w);
    }

    long long ans = 1;
    free_edges = n;
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        cur_ans = 0;
        dfs(i);
        ans = (ans * cur_ans) % MODULUS;
    }
    ans = ans * pow2[free_edges] % MODULUS;
    printf("%I64d\n", (ans + MODULUS) % MODULUS);

    return 0;
}