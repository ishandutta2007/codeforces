#include <cstdio>
#include <cstring>
#include <vector>

static const int MAXN = 78;
static int n;
static char s[MAXN];
static std::vector<int> v, k, o;

static int f[MAXN][MAXN][MAXN][2];

template <typename T> static inline void upd_min(T &var, const T val) { if (var > val) var = val; }

int main()
{
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) switch (s[i]) {
        case 'V': v.push_back(i); break;
        case 'K': k.push_back(i); break;
        default: o.push_back(i); break;
    }

    memset(f, 0x7f, sizeof f);
    f[0][0][0][0] = 0;
    for (int x = 0; x <= v.size(); ++x)
        for (int y = 0; y <= k.size(); ++y)
            for (int z = 0; z <= o.size(); ++z)
                for (int u = 0; u <= 1; ++u) {
                    if (x < v.size()) {
                        int dist = 0;
                        for (int i = y; i < k.size(); ++i)
                            if (k[i] < v[x]) ++dist;
                        for (int i = z; i < o.size(); ++i)
                            if (o[i] < v[x]) ++dist;
                        upd_min(f[x + 1][y][z][1], f[x][y][z][u] + dist);
                    }
                    if (y < k.size() && !u) {
                        int dist = 0;
                        for (int i = x; i < v.size(); ++i)
                            if (v[i] < k[y]) ++dist;
                        for (int i = z; i < o.size(); ++i)
                            if (o[i] < k[y]) ++dist;
                        upd_min(f[x][y + 1][z][0], f[x][y][z][u] + dist);
                    }
                    if (z < o.size()) {
                        int dist = 0;
                        for (int i = x; i < v.size(); ++i)
                            if (v[i] < o[z]) ++dist;
                        for (int i = y; i < k.size(); ++i)
                            if (k[i] < o[z]) ++dist;
                        upd_min(f[x][y][z + 1][0], f[x][y][z][u] + dist);
                    }
                }

    printf("%d\n", std::min(f[v.size()][k.size()][o.size()][0], f[v.size()][k.size()][o.size()][1]));
    return 0;
}