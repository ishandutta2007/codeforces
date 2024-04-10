#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

struct DSU {
    
    void clear(int n) {
        memset(p, -1, n * sizeof(int));
    }
    
    inline int get(int u)
    {
        int res = u;
        while (p[res] >= 0) {
            res = p[res];
        }
        while (p[u] >= 0) {
            int next = p[u];
            p[u] = res;
            u = next;
        }
        return res;
    }
    
    inline bool unite(int u, int v)
    {
        u = get(u);
        v = get(v);
        if (u == v) {
            return false;
        }
        if (p[u] > p[v]) {
            p[u] = v;
        } else {
            if (p[u] == p[v]) {
                --p[u];
            }
            p[v] = u;
        }
        return true;
    }
    
private:
    int p[500];
};

DSU dsu;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> x(m);
    std::vector<int> y(m);
    for (int i = 0; i < m; i++) {
        std::cin >> x[i] >> y[i];
        --x[i];
        --y[i];
    }
    int k;
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int from, to;
        std::cin >> from >> to;
        dsu.clear(n);
        int components = n;
        for (int i = 0; i < from - 1; i++) {
            components -= dsu.unite(x[i], y[i]);
        }
        for (int i = to; i < m; i++) {
            components -= dsu.unite(x[i], y[i]);
        }
        std::cout << components << '\n';
    }
}