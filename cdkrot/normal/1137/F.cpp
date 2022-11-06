// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

struct segm_t {
    int start;
    mutable int end;
    int color;

    bool operator<(const segm_t& other) const {
        return start < other.start;
    }
};

int fenw_sum(vector<int>& fenw, int r) {
    //return std::accumulate(fenw.begin(), fenw.begin() + (r + 1), 0);
    int res = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res += fenw[r];

    return res;
}

void fenw_incr(vector<int>& fenw, int i, int x) {
    //fenw[i] += x;
    for (; i < SZ(fenw); i = i | (i + 1))
        fenw[i] += x;
}

struct dsu_t {
    dsu_t() {}

    void init(int n) {
        par.resize(n);
        std::iota(ALL(par), 0);
    }

    int get(int v) {
        return (v == par[v] ? v : (par[v] = get(par[v])));
    }
    
    vector<int> par;
};

struct path_t {
    vector<int> vert;

    set<segm_t> segms;

    dsu_t up;
    
    void kek(int from, int to, int color, vector<int>& color_fenw, vector<int>& orig_sums, vector<int>& where) {
        int end_color = -1;

        auto it = segms.lower_bound(segm_t {from, -1, -1});
        if (it != segms.begin()) {
            --it;
            
            end_color = it->color;
            if (it->end != from - 1) {
                fenw_incr(color_fenw, it->color, -it->end + (from - 1));
                it->end = from - 1;
            }

            ++it;
        }

        while (it->start <= to) {
            end_color = it->color;
            fenw_incr(color_fenw, it->color, - (it->end - it->start + 1));
            
            ++it;
            segms.erase(std::prev(it));
        }

        if (it->start != to + 1) {
            segm_t sg = {to + 1, it->start - 1, end_color};
            segms.insert(sg);

            fenw_incr(color_fenw, sg.color, sg.end - sg.start + 1);
        }

        segm_t sg = {from, to, color};
        segms.insert(sg);
        
        fenw_incr(color_fenw, sg.color, sg.end - sg.start + 1);


        while (true) {
            int v = up.get(from);
            if (v > to)
                break;

            fenw_incr(orig_sums, where[vert[v]], -1);
            up.par[v] = v + 1;
        }
    }
};

const int max_n = 5.1e5;

int path_no[max_n];
int path_ind[max_n];

vector<path_t> paths;

const int log_n = 21;
int up[log_n][max_n];

int depth[max_n];

int dfs(const vector<vector<int>>& graph, int v, int p) {
    up[0][v] = p;
    for (int k = 1; k < log_n; ++k)
        up[k][v] = up[k - 1][up[k - 1][v]];

    depth[v] = (v == 0 ? 0 : depth[p] + 1);
    
    int sm = 1;

    pair<int, int> largest = {-1, -1};
    
    for (int u: graph[v])
        if (u != p) {
            auto rs = dfs(graph, u, v);
            sm += rs;
            
            largest = max(largest, make_pair(rs, u));
        }

    if (largest.second == -1) {
        path_no[v] = SZ(paths);
        paths.resize(SZ(paths) + 1);
    } else {
        path_no[v] = path_no[largest.second];
    }

    path_ind[v] = SZ(paths[path_no[v]].vert);
    paths[path_no[v]].vert.push_back(v);
    
    return sm;
}

int la(int v, int d) {
    for (int k = log_n - 1; k >= 0; --k)
        if (d >= (1 << k)) {
            d -= (1 << k);

            v = up[k][v];
        }

    return v;
}

int lca(int v, int u) {
    if (not (depth[v] >= depth[u]))
        swap(v, u);

    v = la(v, depth[v] - depth[u]);

    if (v == u)
        return v;

    for (int k = log_n - 1; k >= 0; --k)
        if (up[k][v] != up[k][u]) {
            v = up[k][v];
            u = up[k][u];
        }

    return up[0][v];
}

int dist(int v, int u) {
    return depth[v] + depth[u] - 2 * depth[lca(v, u)];
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int q = input<int>();

    vector<vector<int>> graph(n);
    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<int> order;
    vector<int> where(n, -1);

    vector<int> orig_sums(n);
    for (int i = 0; i != n; ++i)
        fenw_incr(orig_sums, i, 1);
    
    int boss = n - 1;
    if (1) {
        vector<int> deg(n);
        set<int> avail;

        for (int i = 0; i != n; ++i)
            if ((deg[i] = SZ(graph[i])) == 1)
                avail.insert(i);

        while (not avail.empty()) {
            int v = *(avail.begin());
            avail.erase(avail.begin());
            order.push_back(v);
            where[v] = SZ(order) - 1;
            
            for (int u: graph[v])
                if ((--deg[u]) == 1)
                    avail.insert(u);
        }       
    }

    dfs(graph, 0, 0); 
    for (int i = 0; i != SZ(paths); ++i) {
        paths[i].segms = {{0, SZ(paths[i].vert) - 1, 0}, {SZ(paths[i].vert), SZ(paths[i].vert), -1}};

        paths[i].up.init(SZ(paths[i].vert) + 1);
    }
    
    vector<int> fenw_by_color(q + 1, 0);
    fenw_incr(fenw_by_color, 0, n);

    vector<pair<int, int>> color_inf(q + 1, make_pair(-1, -1));
    
    auto when = [&](int v) {
        int ans = 0;
        
        auto it = paths[path_no[v]].segms.upper_bound(segm_t {path_ind[v], -1, -1});
        int color = std::prev(it)->color;

        ans += fenw_sum(fenw_by_color, color - 1);

        if (color == 0) {
            ans += fenw_sum(orig_sums, where[v] - 1);
        } else {
            ans += dist(color_inf[color].first, v);
        }

        return ans;
    };

    auto kek_path = [&](int from, int to, int color) {
        while (path_no[from] != path_no[to]) {
            int end = paths[path_no[from]].vert.back();
            
            paths[path_no[from]].kek(path_ind[from], path_ind[end], color, fenw_by_color, orig_sums, where);
            
            from = up[0][end];
        }

        paths[path_no[from]].kek(path_ind[from], path_ind[to], color, fenw_by_color, orig_sums, where);
    };
    
    auto kek = [&](int v, int i) {
        color_inf[i] = make_pair(boss, v);

        int lc = lca(v, boss);
        kek_path(boss, lc, i);

        if (v != lc)
            kek_path(v, la(v, depth[v] - depth[lc] - 1), i);
        
        boss = v;
    };
    
    for (int i = 1; i <= q; ++i) {
        string tp = input<string>();

        int v = input<int>() - 1;
        int u = (tp == "compare" ? input<int>() - 1 : -1);
        
        if (tp == "up") {
            kek(v, i);
        } else if (tp == "when") {
            cout << when(v) + 1 << "\n";
        } else if (tp == "compare") {
            cout << (when(v) < when(u) ? v : u) + 1 << "\n";
        }

    }
    
    return 0;
}