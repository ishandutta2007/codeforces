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

struct dsu_t {
    vector<int> par;
    dsu_t(int n) {
        par.resize(n);
        std::iota(ALL(par), 0);
    }

    int get(int v) {
        return (v == par[v] ? v : (par[v] = get(par[v])));
    }

    bool merge(int v, int u) {
        v = get(v);
        u = get(u);
        if (v == u)
            return false;
        par[v] = u;
        return true;
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, m;
    cin >> n >> m;

    set<int> alive;
    for (int i = 0; i < n; ++i)
        alive.insert(i);
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    dsu_t dsu(n);

    set<pair<int, int>> list;
    for (int i = 0; i < n; ++i)
        list.emplace(i, i);
    
    int theans = n - 1;
    
    for (int v = 0; v < n; ++v) {
        int prev = -1;
                
        for (int u: graph[v]) {
            auto it = list.lower_bound(make_pair(u + 1, -1));
            assert (it != list.begin());
            --it;

            auto elem = *it;
            list.erase(it);

            if (get<0>(elem) != u)
                list.emplace(get<0>(elem), u - 1);
            if (u != get<1>(elem))
                list.emplace(u + 1, get<1>(elem));
        }

        vector<pair<int, int>> lst_new;
        for (auto pr: list) {
            if (lst_new.size())
                theans -= dsu.merge(pr.first, lst_new.back().first);

            if (lst_new.size() and lst_new.back().second == pr.first - 1)
                lst_new.back().second = pr.second;
            else
                lst_new.push_back(pr);
        }

        list.clear();
        for (auto elem: lst_new)
            list.insert(elem);

        for (auto u: graph[v]) {
            list.emplace(u, u);
        }
    }

    cout << theans << "\n";
    
    return 0;
}