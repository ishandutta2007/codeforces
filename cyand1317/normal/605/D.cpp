#include <cstdio>
#include <algorithm>
#include <deque>
#include <map>
#include <utility>
#include <vector>
static const int MAXN = 100004;
static const int MAXP = 3200004;
static const int INF = 0x7ffffade;
template <typename T> inline T abs(const T x) { return x > 0 ? x : -x; }

int n, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
std::pair<int, int> p[MAXN * 2];    // Divide-and-conquer is based on this array
int p_id[MAXN * 2];
int point_ct = 0;
std::map<std::pair<int, int>, int> id, spell_id;

std::vector<int> e[MAXP];
int dist[MAXP], pred[MAXP];
int route[MAXN];

inline int get_id(const std::pair<int, int> coord) {
    std::map<std::pair<int, int>, int>::iterator p = id.find(coord);
    if (p == id.end()) { id.insert(std::make_pair(coord, ++point_ct)); return point_ct; }
    else return p->second;
}
inline int get_id(int x, int y) {
    return get_id(std::make_pair(x, y));
}

void divide_and_connect(int l, int r)
{
    if (r - l <= 6) {
        for (int i = l; i <= r; ++i) if (p[i].first % 2 == 0)
            for (int j = i + 1; j <= r; ++j)
                if (p[i].second < p[j].second) e[p_id[j]].push_back(p_id[i]);
        return;
    }

    int m = (l + r) >> 1;
    static int ys[MAXN * 2], ys_id[MAXN * 2];
    for (int i = l; i <= r; ++i) ys[i - l] = p[i].second;
    std::sort(ys, ys + (r - l + 1));
    int y_ct = std::unique(ys, ys + (r - l + 1)) - &ys[0];
    int x_m = p[m].first;
    for (int i = 0; i < y_ct; ++i) ys_id[i] = get_id(x_m, ys[i]);

    for (int i = l; i <= r; ++i) {
        if (p[i].first < x_m && p[i].first % 2 == 0) {
            e[get_id(std::make_pair(x_m, p[i].second))].push_back(p_id[i]);
        } else if (p[i].first > x_m) {
            e[p_id[i]].push_back(get_id(std::make_pair(x_m, p[i].second)));
        }
    }
    for (int i = 1; i < y_ct; ++i)
        if (ys[i - 1] % 2 == 0)
            e[ys_id[i]].push_back(ys_id[i - 1]);
        else if (i >= 2)
            e[ys_id[i]].push_back(ys_id[i - 2]);

    divide_and_connect(l, m);
    divide_and_connect(m + 1, r);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        a[i] *= 2; b[i] *= 2; c[i] *= 2; d[i] *= 2;
        if (i == n - 1) ++c[i], ++d[i];
        p[i + i] = std::make_pair(a[i], b[i]);
        p[i+i+1] = std::make_pair(c[i], d[i]);
    }
    p[n * 2] = std::make_pair(0, 0);
    std::sort(p, p + n * 2 + 1);
    int orig_point_ct = std::unique(p, p + n * 2 + 1) - &p[0];
    for (int i = 0; i < orig_point_ct; ++i) p_id[i] = get_id(p[i]);

    divide_and_connect(0, orig_point_ct - 1);

    for (int i = 0; i < n; ++i) {
        int u = get_id(a[i], b[i]), v = get_id(c[i], d[i]);
        e[u].push_back(-v);
        spell_id[std::make_pair(u, v)] = i + 1;
    }

    for (int i = 0; i <= point_ct; ++i) dist[i] = INF, pred[i] = -1;
    int source = get_id(0, 0), sink = get_id(c[n - 1], d[n - 1]);
    dist[source] = 0, pred[source] = -2;
    std::deque<int> q; q.push_back(source);
    while (!q.empty() && dist[sink] == INF) {
        int u = q.front(); q.pop_front();
        for (std::vector<int>::iterator i = e[u].begin(); i != e[u].end(); ++i) {
            if (*i > 0) {   // Zero edge
                if (dist[*i] > dist[u]) {
                    dist[*i] = dist[u], pred[*i] = u;
                    q.push_front(*i);
                }
            } else {        // One edge
                if (dist[-*i] > dist[u] + 1) {
                    dist[-*i] = dist[u] + 1, pred[-*i] = u;
                    q.push_back(-*i);
                }
            }
        }
    }

    if (dist[sink] == INF) { puts("-1"); return 0; }
    printf("%d\n", dist[sink]);
    int route_top = 0;
    for (int u = sink; u != source; u = pred[u]) {
        if (dist[u] != dist[pred[u]]) route[route_top++] = spell_id[std::make_pair(pred[u], u)];
    }
    for (int i = route_top - 1; i >= 0; --i) printf("%d%c", route[i], i == 0 ? '\n' : ' ');

    return 0;
}