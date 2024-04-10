#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long int64;
static const int MAXN = 100004;

int n;
int p[MAXN];
bool vis[MAXN] = { false };
std::vector<int> cyc;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]), --p[i];

    for (int i = 0; i < n; ++i) if (!vis[i]) {
        int sz = 0, u = i;
        do {
            vis[u] = true;
            u = p[u];
            ++sz;
        } while (u != i);
        cyc.push_back(sz);
    }

    std::sort(cyc.begin(), cyc.end());
    if (cyc.size() >= 2) {
        int x = cyc[cyc.size() - 1] + cyc[cyc.size() - 2];
        cyc.resize(cyc.size() - 2);
        cyc.push_back(x);
    }

    int64 ans = 0;
    for (int u : cyc) ans += (int64)u * u;
    printf("%I64d\n", ans);

    return 0;
}