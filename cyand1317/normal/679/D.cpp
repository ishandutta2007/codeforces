#include <cstdio>
#include <cstring>
#include <vector>
static const int INF = 0x3fffffff;
static const int MAXN = 418;    // I'm a teapot =u=
typedef std::vector<int> edgelist;

template <typename T> inline T min(const T a, const T b) {
    return a < b ? a : b;
}
template <typename T> inline T max(const T a, const T b) {
    return a > b ? a : b;
}

int n, m;
edgelist e[MAXN];
int d[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            d[i][j] = (i == j ? 0 : INF);

    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v); --u; --v;
        e[u].push_back(v);
        e[v].push_back(u);
        d[u][v] = d[v][u] = 1;
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    double ans = 0.0;
    for (int g1 = 0; g1 < n; ++g1) {
        double cur = 0.0;
        for (int d1 = 0; d1 < n; ++d1) {
            int valid_ct = 0;
            for (int i = 0; i < n; ++i)
                if (d[g1][i] == d1) ++valid_ct;
            if (valid_ct == 0) continue;

            double nextday = 0.0;
            std::vector<int> omoshiroi;
            static double prob[MAXN], prob_in_dist[MAXN];
            memset(prob, 0, sizeof prob);
            //memset(prob_in_dist, 0, sizeof prob_in_dist);
            for (int u = 0; u < n; ++u) if (d[g1][u] == d1)
                for (edgelist::iterator v = e[u].begin(); v != e[u].end(); ++v) {
                    if (prob[*v] == 0) omoshiroi.push_back(*v);
                    prob[*v] += 1.0 / valid_ct / e[u].size();
                }
            for (int g2 = 0; g2 < n; ++g2) {
                double cur = 0.0;
                for (std::vector<int>::iterator i = omoshiroi.begin(); i != omoshiroi.end(); ++i)
                    prob_in_dist[d[g2][*i]] = max(prob_in_dist[d[g2][*i]], prob[*i]);
                for (std::vector<int>::iterator i = omoshiroi.begin(); i != omoshiroi.end(); ++i) {
                    cur += prob_in_dist[d[g2][*i]];
                    prob_in_dist[d[g2][*i]] = 0.0;
                }
                nextday = max(nextday, cur);
            }

            // http://codeforces.com/blog/entry/45310#comment-298820
            cur += max(1.0 / valid_ct, nextday) * valid_ct / n;
        }
        ans = max(ans, cur);
    }

    printf("%.12lf\n", ans);
    return 0;
}