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

const int max_n = 2.1e5;
int fact[max_n];

const int mod = 998244353;
int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int dfs(const vector<vector<int>>& graph, int v, int p) {
    int deg = SZ(graph[v]);
    if (p != -1)
        --deg;

    int ans;

    if (p == -1)
        ans = mult(fact[deg], SZ(graph));
    else
        ans = fact[deg + 1];

    for (int u: graph[v])
        if (u != p)
            ans = mult(ans, dfs(graph, u, v));
    
    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    fact[0] = 1;
    for (int i = 1; i < max_n; ++i)
        fact[i] = mult(i, fact[i - 1]);
        
    int n = input<int>();

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    int ans = dfs(graph, 0, -1);

    cout << ans << "\n";
    
    return 0;
}