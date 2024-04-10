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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<vector<int>> graph(n);

    // author, you suck
    if (n == 1) {
        return 0;
    }
    
    // author, you suck
    if (n == 2) {
        cout << "1 2 228\n";
        return 0;
    }
    
    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    vector<int> sz(n);
    std::function<void(int, int)> dfs = [&](int v, int p) {
        sz[v] = 1;
        for (int u: graph[v])
            if (u != p) {
                dfs(u, v);
                sz[v] += sz[u];
            }
    };

    dfs(0, -1);

    int c = 0;
    bool work = true;
    while (work) {
        work = false;
        
        for (int elem: graph[c])
            if (sz[elem] < sz[c] and 2 * sz[elem] >= n) {
                c = elem;
                work = true;
                break;
            }
    }

    dfs(c, -1);
    sort(ALL(graph[c]), [&](int a, int b) {
        return sz[a] > sz[b];
    });

    vector<char> mark(n, -1);
    std::function<void(int, int, int)> dfs_mark = [&](int v, int p, int mrk) {
        mark[v] = mrk;
        for (int u: graph[v])
            if (u != p)
                dfs_mark(u, v, mrk);
    };
    
    vector<int> p1, p2;
    int w1 = 0, w2 = 0;
    for (int el: graph[c])
        if (w1 <= w2) {
            p1.push_back(el);
            w1 += sz[el];
            dfs_mark(el, c, 1);
        } else {
            p2.push_back(el);
            w2 += sz[el];
            dfs_mark(el, c, 2);
        }

    int ptr1 = 1;
    int ptr2 = w1;
    std::function<void(int, int, int)> dfs_ans = [&](int v, int p, int sm) {
        for (int u: graph[v])
            if (u != p) {
                int x;
                
                if (mark[u] == 1)
                    x = ptr1++;
                else
                    x = ptr2, ptr2 += w1;

                cout << 1 + v << " " << 1 + u << " " << x - sm << "\n";
                dfs_ans(u, v, x);
            }
    };
    
    dfs_ans(c, -1, 0);
    
    return 0;
}