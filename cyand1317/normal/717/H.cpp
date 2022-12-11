#include <cstdio>
#include <cstdlib>
#include <algorithm>
static const int MAXN = 50004;
static const int MAXE = 100004 * 2;
static const int MAXL = 20;
static const int MAXT = 1000005;

int n, e;
int head[MAXN], dest[MAXE], next[MAXE];
int l[MAXN], t[MAXN][MAXL];
int T = 0;

int p[MAXN];
int conf[MAXN], team[MAXN];
int team_conf[MAXT];

inline void add_edge(int u, int v) {
    // mdzzmdzzmdzz!!
    static int w = 0; dest[w] = v; next[w] = head[u]; head[u] = w++;
}

int main()
{
    scanf("%d%d", &n, &e);
    for (int i = 0; i < n; ++i) head[i] = -1;
    int u, v;
    for (int i = 0; i < e; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &l[i]);
        for (int j = 0; j < l[i]; ++j) {
            scanf("%d", &t[i][j]); --t[i][j];
            T = std::max(T, t[i][j]);
        }
    }
    ++T;

    srand(87665544);
    for (int i = 0; i < n; ++i) p[i] = i;
    for (int attempts = 0; ; ++attempts) {
        if (attempts % 16 == 0) {
            std::random_shuffle(p, p + n);
            std::fill(conf, conf + n, -1);
            int ct[2];
            for (int i = 0; i < n; ++i) {
                ct[0] = ct[1] = 0;
                for (int w = head[p[i]]; w != -1; w = next[w]) {
                    if (conf[dest[w]] != -1) ++ct[conf[dest[w]]];
                }
                conf[p[i]] = (ct[0] > ct[1] ? 1 : 0);
            }
        }

        for (int i = 0; i < T; ++i) team_conf[i] = rand() % 2;

        bool valid = true;
        for (int i = 0; i < n; ++i) {
            team[i] = -1;
            for (int j = 0; j < l[i]; ++j)
                if (conf[i] == team_conf[t[i][j]]) { team[i] = t[i][j]; break; }
            if (team[i] == -1) { valid = false; break; }
        }

        if (!valid) continue;
        for (int i = 0; i < n; ++i) printf("%d%c", team[i] + 1, i == n - 1 ? '\n' : ' ');
        for (int i = 0; i < T; ++i) printf("%d%c", team_conf[i] + 1, i == T - 1 ? '\n' : ' ');
        break;
    }

    return 0;
}