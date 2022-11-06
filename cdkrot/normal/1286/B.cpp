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

    vector<int> C(n);
    vector<vector<int>> graph(n);
    int root = -1;

    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p >> C[i];

        --p;
        if (p == -1)
            root = i;
        else
            graph[p].push_back(i);
    }

    std::function<vector<int>(int)> dfs = [&](int v) {
        vector<int> rs;
        
        for (auto u: graph[v]) {
            auto ch = dfs(u);

            for (int elem: ch)
                rs.push_back(elem);
        }

        if (C[v] > SZ(rs)) {
            cout << "NO\n";
            exit(0);
        }

        rs.insert(rs.begin() + C[v], v);
        return rs;
    };

    auto rs = dfs(root);

    vector<int> x(n);
    for (int i = 0; i < n; ++i)
        x[rs[i]] = i + 1;

    cout << "YES\n";
    
    for (int i = 0; i < n; ++i)
        cout << x[i] << " \n"[i + 1==n];
    
    return 0;
}