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

const string win = "White";
const string draw = "Draw";

void solve() {
    int n = input<int>();
    vector<vector<int>> graph(n);

    auto add_edge = [&](int v, int u) {
        graph[v].push_back(u);
        graph[u].push_back(v);
    };
    
    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        add_edge(v, u);
    }

    string marks = input<string>();

    for (int v = n - 1; v >= 0; --v)
        if (marks[v] == 'W') {
            graph.resize(n + 3);
            add_edge(v, n);
            add_edge(n, n + 1);
            add_edge(n, n + 2);
            
            n += 3;
        }
    
    int maxdeg = -1;
    int cnt = 0;
    for (int v = 0; v != n; ++v)
        if (SZ(graph[v]) > maxdeg) {
            maxdeg = SZ(graph[v]);
            cnt = 1;
        } else if (SZ(graph[v]) == maxdeg) {
            ++cnt;
        }

    if (maxdeg >= 4 or (maxdeg == 3 and cnt >= 3)) {
        cout << win << "\n";
        return;
    }

    if (maxdeg == 3) {
        for (int v = 0; v != n; ++v) {
            if (graph[v].size() == 3) {
                int u1 = graph[v][0];
                int u2 = graph[v][1];
                int u3 = graph[v][2];

                if (int(SZ(graph[u1]) == 1) + int(SZ(graph[u2]) == 1)  + int(SZ(graph[u3]) == 1) <= 1) {
                    cout << win << "\n";
                    return;
                }
            }
        }
    }

    if (maxdeg == 3 and cnt == 2 and n % 2 == 1) {
        cout << win << "\n";
        return;
    }
    
    cout << draw << "\n";
    return;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here

    for (int t = input<int>(); t != 0; --t)
        solve();
}