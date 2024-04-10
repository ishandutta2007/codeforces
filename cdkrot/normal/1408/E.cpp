// Dmitry _kun_ Sayutin (2020)

#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;
using std::queue;

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

struct elem_t {
    int val;
    int cost;
    int id;
};

struct dsu_t {
    vector<int> par;
    
    dsu_t(int n): par(n) {
        std::iota(ALL(par), 0);
    }

    int get(int v) {
        return (v == par[v] ? v : (par[v] = get(par[v])));
    }

    void join(int v, int u) {
        v = get(v);
        u = get(u);
        par[v] = u;
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int m, n;
    cin >> m >> n;

    vector<int> a(m), b(n);
    input_seq(ALL(a));
    input_seq(ALL(b));

    vector<elem_t> elems;
    for (int i = 0; i < m; ++i) {
        int size = input<int>();

        for (int it = 0; it < size; ++it) {
            elem_t elem;
            elem.val = input<int>() - 1;
            elem.cost = a[i] + b[elem.val];
            elem.id = i;

            elems.push_back(elem);
        }
    }

    sort(ALL(elems), [&](elem_t a, elem_t b) {return a.cost > b.cost;});

    vector<int> last(m, -1);

    dsu_t dsu(n);
    int64_t cost = 0;

    for (auto elem: elems) {
        if (last[elem.id] != -1) {
            if (dsu.get(last[elem.id]) == dsu.get(elem.val))
                cost += elem.cost;
            else
                dsu.join(last[elem.id], elem.val);
        }
        
        last[elem.id] = elem.val;
    }

    cout << cost << "\n";

    return 0;
}