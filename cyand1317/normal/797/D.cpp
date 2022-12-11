#include <cstdio>
#include <algorithm>
#include <map>
static const int MAXN = 1e5 + 4;

int n, v[MAXN], l[MAXN], r[MAXN];
bool not_root[MAXN] = { false };
std::map<int, int> count;
int ans = 0;

void dfs(int u, int L, int R)
{
    if (L > R) return;
    if (v[u] >= L && v[u] <= R) ans += count[v[u]], count[v[u]] = 0;
    if (l[u] >= 0) dfs(l[u], L, std::min(R, v[u] - 1));
    if (r[u] >= 0) dfs(r[u], std::max(L, v[u] + 1), R);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &v[i], &l[i], &r[i]);
        if (l[i] > 0) not_root[--l[i]] = true;
        if (r[i] > 0) not_root[--r[i]] = true;
        ++count[v[i]];
    }

    int root = 0;
    while (not_root[root]) ++root;
    dfs(root, -1e9, 1e9);
    printf("%d\n", n - ans);

    return 0;
}