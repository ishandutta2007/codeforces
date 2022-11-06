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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<double> pr(n);

    for (int i = 0; i < n; ++i)
        cin >> pr[i];

    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<int> HEAVY;
    vector<char> is_heavy(n, false);
    for (int i = 0; i < n; ++i)
        if (SZ(graph[i]) >= 500) {
            HEAVY.push_back(i);
            is_heavy[i] = true;
        }

    vector<vector<int>> subgr(n);
    for (int v = 0; v < n; ++v)
        for (int u: graph[v])
            if (is_heavy[u])
                subgr[v].push_back(u);

    // c = n - m
    double ans = 0;
    
    for (int i = 0; i < n; ++i)
        ans += (1.0 - pr[i]);
    
    for (int v = 0; v < n; ++v)
        for (int u: graph[v])
            if (v < u)
                ans -= (1 - pr[v]) * (1 - pr[u]);

    vector<double> sums_for_disabled(n);
    for (int i = 0; i < n; ++i)
        if (is_heavy[i]) {
            for (int u: graph[i])
                sums_for_disabled[i] += (1 - pr[u]);
        }
    
    auto account = [&](int v, int w) {
        ans += w * (1.0 - pr[v]);

        if (is_heavy[v]) {
            ans -= w * (1 - pr[v]) * sums_for_disabled[v];
        } else {
            for (int u: graph[v])
                ans -= w * (1 - pr[v]) * (1 - pr[u]);
        }

        for (int u: subgr[v])
            sums_for_disabled[u] += w * (1 - pr[v]);
    };
    
    for (int Q = input<int>(); Q != 0; --Q) {        
        int x = input<int>();
        account(x, -1);
        pr[x] = input<double>();
        account(x, +1);
        
        cout << std::fixed;
        cout.precision(6);
        cout << ans << "\n";
    }
        
    return 0;
}