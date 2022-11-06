// 2018, Sayutin Dmitry.

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

#define pb push_back
#define eb emplace_back

template <typename T>
struct vec {
    T x; T y;
};

template <typename T>
vec<T> operator+(vec<T> a, vec<T> b) {
    return vec<T> {a.x + b.x, a.y + b.y};
}

template <typename T>
vec<T> operator-(vec<T> a, vec<T> b) {
    return vec<T> {a.x - b.x, a.y - b.y};
}

template <typename U, typename T>
vec<U> cast(vec<T> v) {
    return vec<U> {(U)v.x, (U)v.y};
}

int64_t cross64(vec<int> a, vec<int> b) {
    return a.x * int64_t(b.y) - b.x * int64_t(a.y);
}
int64_t dot64(vec<int> a, vec<int> b) {
    return a.x * int64_t(b.x) + a.y * int64_t(b.y);
}

int64_t dist2(vec<int> a) {
    return a.x * int64_t(a.x) + a.y * int64_t(a.y);
}

template <typename T>
vec<T> rot90(vec<T> a) {
    return vec<T> {-a.y, a.x};
}

vector<vec<int>> minkowsky_sum(vector<vec<int>> a, vector<vec<int>> b) {
    auto kek = [&](vector<vec<int>>& v) {
        auto it = std::min_element(ALL(v), [](vec<int> u, vec<int> w) {
                return make_pair(u.x, u.y) < make_pair(w.x, w.y);
            });

        std::rotate(v.begin(), it, v.end());
    };
    
    kek(a);
    kek(b);

    int n = SZ(a);
    int m = SZ(b);
    
    a.push_back(a[0]);
    a.push_back(a[1]);
    b.push_back(b[0]);
    b.push_back(b[1]);

    vector<vec<int>> res;
    
    int p = 0, q = 0;
    while (p < n or q < m) {
        res.push_back(a[p] + b[q]);

        if (cross64(a[p + 1] - a[p], b[q + 1] - b[q]) > 0)
            ++p;
        else if (cross64(a[p + 1] - a[p], b[q + 1] - b[q]) < 0)
            ++q;
        else
            ++p, ++q;
    }

    return res;
}

bool inside(const vector<vec<int>>& poly, vec<int> pt) {
    for (int i = 0; i != SZ(poly); ++i) {
        int j = (i + 1) % SZ(poly);

        if (cross64(poly[i] - pt, poly[j] - pt) == 0 and dot64(poly[i] - pt, poly[j] - pt) <= 0)
            return true;
    }

    double ang = 0;
    for (int i = 0; i != SZ(poly); ++i) {
        int j = (i + 1) % SZ(poly);

        ang += atan2(cross64(poly[i] - pt, poly[j] - pt), dot64(poly[i] - pt, poly[j] - pt));
    }

    return abs(ang - 2.0 * acos(-1)) < 1e-3;
}


bool ok(const vector<vec<int>>& poly, vec<int> pt, int rad) {
    for (auto elem: poly)
        if (dist2(pt - elem) < rad * int64_t(rad))
            return false;

    if (inside(poly, pt))
        return false;    

    for (int i = 0; i != SZ(poly); ++i) {
        auto p = poly[i];
        auto q = poly[(i + 1) % SZ(poly)];

        if (dot64(q - p, pt - p) <= 0)
            continue;
        if (dot64(p - q, pt - q) <= 0)
            continue;

        auto norm = rot90(q - p);
        int64_t c = norm.x * p.x + norm.y * p.y;

        int64_t dst = abs(norm.x * pt.x + norm.y * pt.y - c);
        // dst / sqrt(||norm||) < rad
        
        if (dst * dst < rad * rad * dist2(norm))
            return false;
    }
    return true;
}

struct edge_t {
    int to;
    int flow;
    int cap;
    int next;
};

int push(vector<int>& head, vector<edge_t>& edges, vector<char>& used, int v, int T, int mx) {
    if (v == T)
        return mx;

    used[v] = 1;

    for (int e = head[v]; e != -1; e = edges[e].next)
        if (edges[e].flow < edges[e].cap and not used[edges[e].to]) {
            int val = push(head, edges, used, edges[e].to, T, min(mx, edges[e].cap - edges[e].flow));
            if (val > 0) {
                edges[e].flow += val;
                edges[e ^ 1].flow -= val;

                return val;
            }
        }

    return 0;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int min_x = TYPEMAX(int), max_x = TYPEMIN(int);
    
    int n = input<int>();
    int w = input<int>();

    vector<vec<int>> poly(n);
    for (int i = 0; i != n; ++i) {
        cin >> poly[i].x >> poly[i].y;

        min_x = min(min_x, poly[i].x);
        max_x = max(max_x, poly[i].x);
    }

    for (int i = 0; i != n; ++i)
        poly[i].x -= min_x;

    max_x -= min_x;
    
    int m = input<int>();
    vector<pair<vec<int>, int>> jelly(m);
    for (auto& elem: jelly)
        cin >> elem.first.x >> elem.first.y >> elem.second;

    vector<vec<int>> antipoly(n);
    for (int i = 0; i != n; ++i)
        antipoly[i] = {-poly[i].x, -poly[i].y};

    auto poly_minus_poly = minkowsky_sum(poly, antipoly);
    
    int S = 2 * m;
    int T = 2 * m + 1;
    vector<int> head(2 * m + 2, -1);
    vector<edge_t> edges;

    auto add_edge = [&](int v, int u, int cap, int rcap) {
        edges.push_back(edge_t {u, 0, cap, head[v]});
        head[v] = SZ(edges) - 1;
        edges.push_back(edge_t {v, 0, rcap, head[u]});
        head[u] = SZ(edges) - 1;
    };

    const int inf = 1e3;

    for (int i = 0; i < m; ++i)
        add_edge(2 * i + 1, 2 * i, 1, 0);
    
    for (int i = 0; i < m; ++i)
        for (int j = i + 1; j < m; ++j) {
            if (not ok(poly_minus_poly, jelly[i].first - jelly[j].first, jelly[i].second + jelly[j].second)) {
                add_edge(2 * i, 2 * j + 1, inf, 0);
                add_edge(2 * j, 2 * i + 1, inf, 0);

#ifdef LOCAL
                cerr << i + 1 << " " << j + 1 << "\n";
#endif
            }
        }

    for (int i = 0; i != m; ++i) {
        int L = jelly[i].first.x - jelly[i].second - max_x;
        int R = jelly[i].first.x + jelly[i].second;

        if (L < 0) {
            add_edge(S, 2 * i + 1, inf, 0);
#ifdef LOCAL
            cerr << "S " << i + 1 << "\n";
#endif
        }
        
        if (R > w - max_x) {
            add_edge(2 * i, T, inf, 0);
#ifdef LOCAL
            cerr << "T " << i + 1 << "\n";
#endif
        }
    }
    
    int flow = 0;
    while (true) {
        vector<char> used(2 * m + 2, false);
        int tmp;
        if ((tmp = push(head, edges, used, S, T, TYPEMAX(int))) != 0)
            flow += tmp;
        else
            break;
    }

    cout << flow << "\n";
    
    return 0;
}