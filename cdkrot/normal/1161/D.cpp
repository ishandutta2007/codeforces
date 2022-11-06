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

const int mod = 998244353;
int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}


struct edge_t {
    int to;
    bool same;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    string s;
    cin >> s;

    std::reverse(ALL(s));
    
    int ans = 0;
    for (int len = 1; len < SZ(s); ++len) {
        vector<vector<edge_t>> graph(SZ(s) + len);
        
        int off1 = 0;
        int off2 = SZ(s);

        auto add_edge = [&](int v, int u, bool sm) {
            graph[v].push_back(edge_t {u, sm});
            graph[u].push_back(edge_t {v, sm});
        };

        for (int i = 0; i != len; ++i) {
            add_edge(off2 + i, off2 + (len - 1 - i), true);
        }

        for (int i = 0; i != SZ(s); ++i) {
            add_edge(off1 + i, off1 + (SZ(s) - 1 - i), true);
        }
        
        for (int i = 0; i < len; ++i) {
            if (s[i] != '?') {
                add_edge(off1 + i, off2 + i, s[i] == '0' ? true : false);
            }
        }

        vector<char> color(SZ(graph), 2);

        std::function<bool(int, int)> dfs = [&](int v, int col) {
            if (color[v] != col and color[v] != 2)
                return false;
            
            if (color[v] == 2)
                color[v] = col;
            else
                return true;
            
            for (auto e: graph[v])
                if (not dfs(e.to, e.same ? col : col ^ 1))
                    return false;

            return true;
        };

        int delta = 1;
        for (int i = len; i < SZ(s); ++i)
            if (s[i] != '?')
                if (not dfs(i, s[i] - '0'))
                    goto fail;

        if (not dfs(off2 + len - 1, 1))
            goto fail;
        
        for (int i = 0; i != SZ(graph); ++i)
            if (color[i] == 2) {
                delta = add(delta, delta);
                
                if (not dfs(i, 0))
                    goto fail;
            }

        ans = add(ans, delta);

    fail:;
    }

    cout << ans << "\n";
    
    return 0;
}