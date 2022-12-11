#include <cstdio>
#include <utility>
#include <vector>

static const int MAXN = 1e5 + 4;
static const int ALPHA = 26;

static int n;
static char s[MAXN], t[MAXN];
static std::vector<std::pair<char, char>> ans;

namespace dsu {
    int p[MAXN];
    inline void init(int n) { for (int i = 0; i < n; ++i) p[i] = i; }
    inline int root(int u) { return (p[u] == u) ? u : (p[u] = root(p[u])); }
    inline void merge(int u, int v) { u = root(u), v = root(v); p[u] = v; }
}

int main()
{
    scanf("%d%s%s", &n, s, t);
    dsu::init(ALPHA);

    for (int i = 0; i < n; ++i) {
        if (dsu::root(s[i] - 'a') != dsu::root(t[i] - 'a')) {
            dsu::merge(s[i] - 'a', t[i] - 'a');
            ans.push_back({s[i], t[i]});
        }
    }

    printf("%lu\n", ans.size());
    for (auto u : ans) printf("%c %c\n", u.first, u.second);

    return 0;
}