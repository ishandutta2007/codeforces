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

void dfs(const vector<vector<int>>& graph, vector<int>& sz, int64_t& base_ans, int v, int p) {
    sz[v] = 1;
    
    for (int u: graph[v]) {
        if (u == p)
            continue;

        dfs(graph, sz, base_ans, u, v);
        sz[v] += sz[u];

        base_ans += (SZ(graph) - sz[u]) * int64_t(sz[u]);
    }
}

// odd, even.
pair<int64_t, int64_t> dfs2(const vector<vector<int>>& graph, int64_t& num_odd, int64_t& num_even, int v, int p) {
    int64_t go_odd = 0, go_even = 1;

    for (int u: graph[v]) {
        if (u == p)
            continue;
        
        auto dp = dfs2(graph, num_odd, num_even, u, v);
        std::swap(dp.first, dp.second);

        num_odd += dp.first  * go_even
            +      dp.second * go_odd;

        num_even += dp.first * go_odd
            +       dp.second * go_even;
        
        go_odd += dp.first;
        go_even += dp.second;
    }

    return make_pair(go_odd, go_even);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<vector<int>> graph(n);
    for (int i = 0; i != n - 1; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int64_t base_ans = 0;
    vector<int> sz(n);

    dfs(graph, sz, base_ans, 0, -1);

    //cerr << base_ans << "\n";

    int64_t num_odd = 0, num_even = 0;
    dfs2(graph, num_odd, num_even, 0, -1);

    //cerr << base_ans << " " << num_odd << "\n";
    
    base_ans += num_odd;
    assert(base_ans % 2 == 0);
    
    cout << base_ans / 2 << "\n";
    
    return 0;
}