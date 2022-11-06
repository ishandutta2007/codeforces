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

const int max_n = 501000;
int tree[4 * max_n];

void build(int v, int l, int r, vector<int>& a) {
    if (l == r - 1) {
        tree[v] = a[l];
    } else {
        int m = l + (r - l) / 2;

        build(2 * v + 1, l, m, a);
        build(2 * v + 2, m, r, a);

        tree[v] = max(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

int get(int v, int nl, int nr, int l, int r) {
    if (l <= nl and nr <= r)
        return tree[v];

    if (nr <= l or r <= nl)
        return -1;

    int m = nl + (nr - nl) / 2;
    return max(get(2 * v + 1, nl, m, l, r),
               get(2 * v + 2, m, nr, l, r));
}

bool dfs(const vector<vector<int>>& graph, vector<char>& used, vector<int>& topsort, int v) {
    used[v] = 1;
    for (int u: graph[v])
        if (used[u] == 1)
            return false;
        else if (used[u] == 0 and not dfs(graph, used, topsort, u))
            return false;

    used[v] = 2;
    topsort.push_back(v);
    return true;
}

void solve() {
    int n = input<int>();

    vector<int> in(n);
    for (int i = 0; i != n; ++i)
        in[i] = input<int>() - 1;

//    build(0, 0, n, in);

    vector<vector<int>> graph(n);

    auto before = [&](int v, int u) {
        graph[u].push_back(v);
    };

    for (int i = 0; i != n; ++i)
        if (in[i] != -2 and in[i] != n)
            before(i, in[i]);
    
    vector<int> window;
    for (int i = 0; i != n; ++i) {
        while (not window.empty() and in[window.back()] <= i)
            window.pop_back();
        
        if (not window.empty()) {
            before(i, window.back());
        }

        if (in[i] != -2) {
            auto bad = [&](int a, int b) {
                assert(a < b and b < in[a]);
                return in[b] > in[a];
            };
            
            if (not window.empty() and bad(window.back(), i)) {
                cout << "-1\n";
                return;
            }

            window.push_back(i);
        }
    }

    vector<int> topsort;
    vector<char> used(n, 0);

    for (int i = 0; i < n; ++i)
        if (used[i] == 0)
            if (not dfs(graph, used, topsort, i)) {
                cout << "-1\n";
                return;
            }
    
    vector<int> ans(n);
    for (int i = 0; i != n; ++i)
        ans[topsort[i]] = i + 1;

    for (int& elem: ans)
        cout << elem << " ";
    cout << "\n";
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    for (int t = input<int>(); t != 0; --t) {
        solve();
    }
    
    return 0;
}