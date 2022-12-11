#include <cstdio>
#include <algorithm>
#include <utility>
static const int MAXN = 100007;
static const int MAXM = 100007;
struct edge {
    int id, weight; bool in_mst;
    int u, v;
    edge() : id(-1), weight(0), in_mst(false), u(-1), v(-1) { }
    edge(int id, int weight, bool in_mst)
        : id(id), weight(weight), in_mst(in_mst), u(-1), v(-1) { }

    static inline bool weight_comparator(const edge lhs, const edge rhs) {
        return lhs.weight < rhs.weight;
    }
    static inline bool id_comparator(const edge lhs, const edge rhs) {
        return lhs.id < rhs.id;
    }
};

int n, m;
edge e[MAXM];

int out_w[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        e[i].id = i;
        scanf("%d%d", &e[i].weight, &e[i].in_mst);
    }
    std::sort(e, e + m, edge::weight_comparator);

    int vert_ptr = 0;
    for (int i = 0; i < m; ++i) if (e[i].in_mst) {
        e[i].u = vert_ptr;
        out_w[vert_ptr] = e[i].weight;
        e[i].v = ++vert_ptr;
    }
    vert_ptr = 1;
    int ydr_ptr = 0;
    bool feasible = true;
    for (int i = 0; i < m; ++i) if (!e[i].in_mst) {
        if (++ydr_ptr >= vert_ptr - 1) {
            if (++vert_ptr >= n || out_w[vert_ptr - 1] > e[i].weight) {
                feasible = false; break;
            }
            ydr_ptr = 0;
        }
        e[i].u = vert_ptr;
        e[i].v = ydr_ptr;
    }
    if (feasible) {
        std::sort(e, e + m, edge::id_comparator);
        for (int i = 0; i < m; ++i) printf("%d %d\n", e[i].u + 1, e[i].v + 1);
    } else {
        puts("-1");
    }
    return 0;
}