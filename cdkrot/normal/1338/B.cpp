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
    vector<vector<int>> graph(n);

    for (int i = 1; i < n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<char> colors(n, -1);
    if (1) {
        queue<int> q;
        q.push(0);
        colors[0] = 0;

        while (not q.empty()) {
            int v = q.front();
            q.pop();

            for (int u: graph[v])
                if (colors[u] == -1) {
                    colors[u] = colors[v] ^ 1;
                    q.push(u);
                }   
        }

        int has = 0;
        for (int i = 0; i < n; ++i)
            if (SZ(graph[i]) == 1)
                has |= (1 << colors[i]);

        cout << (has == 3 ? 3 : 1) << " ";
    }

    int v = 0;
    while (SZ(graph[v]) == 1)
        ++v;

    int ans = 0;
    std::function<void(int, int)> dfs = [&](int v, int p) {
        bool wasleaf = false;
        for (int u: graph[v])
            if (u != p) {
                if (SZ(graph[u]) == 1)
                    wasleaf = true;
                else
                    dfs(u, v), ++ans;
            }

        if (wasleaf)
            ++ans;
    };

    dfs(v, -1);
    cout << ans << "\n";

    return 0;
}