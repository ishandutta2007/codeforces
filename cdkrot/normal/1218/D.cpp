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

struct edge_t {
    int to;
    int w;
};

int fpow(int a, int n, int mod, int r = 1) {
    while (n) {
        if (n % 2)
            r = (int64_t(r) * a) % mod;

        a = (int64_t(a) * a) % mod;
        n /= 2;
    }

    return r;
}

void fft(int k, vector<int>& arr, int mod) {
    for (int lvl = 0; lvl < k; ++lvl)
        for (int off = 0; off < (1 << k); off += (2 << lvl))
            for (int pos = 0; pos < (1 << lvl); ++pos) {
                int a = arr[off + pos];
                int b = arr[off + pos + (1 << lvl)];

                arr[off + pos] = (a + b >= mod ? a + b - mod : a + b);
                arr[off + pos + (1 << lvl)] = (a >= b ? a - b : mod + a - b);
            }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, m;
    cin >> n >> m;

    vector<vector<edge_t>> graph(n);
    int base = 0;
    for (int i = 0; i != m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v, --u;

        graph[v].emplace_back(edge_t {u, w});
        graph[u].emplace_back(edge_t {v, w});
        base ^= w;
    }

    vector<edge_t> up(n, edge_t {-1,-1});
    vector<char> used(n, 0);

    vector<vector<int>> lists;
    
    std::function<void(int, edge_t)> dfs = [&](int v, edge_t p) {
        up[v] = p;
        used[v] = 1;

        for (auto u: graph[v])
            if (used[u.to] == 0) {
                dfs(u.to, edge_t {v, u.w});
            } else if (used[u.to] == 1 and u.to != p.to) {
                // kukareku

                vector<int> list = {u.w};
                for (int w = v; w != u.to; w = up[w].to)
                    list.push_back(up[w].w);

                int xr = 0;
                for (int elem: list)
                    xr ^= elem;

                base ^= xr;
                for (int& elem: list)
                    elem ^= xr;

                lists.push_back(list);
            }
        
        used[v] = 2;
    };

    dfs(0, edge_t {-10, -10});
    lists.push_back(vector<int> {base});

    // for (auto lst: lists) {
    //     for (int elem: lst)
    //         cout << elem << " ";
    //     cout << "\n";
    // }
    
    int mod = int(1e9) + 993;
    int m2 = int(1e9) + 7;

    vector<int> arr(1 << 17, 1);
    vector<int> arr2(1 << 17, 1);
    
    for (auto& el: lists) {
        vector<int> r1(1 << 17), r2(1 << 17);
        for (int v: el) {
            r1[v] += 1;
            r2[v] += 1;
        }   

        fft(17, r1, mod);
        fft(17, r2, m2);
        
        for (int i = 0; i != (1 << 17); ++i) {
            arr[i] = (int64_t(arr[i]) * r1[i]) % mod;
            arr2[i] = (int64_t(arr2[i]) * r2[i]) % m2;
        }
    }

    fft(17, arr, mod);
    fft(17, arr2, m2);
    
    int minpos = 0;
    while (arr[minpos] == 0 and arr2[minpos] == 0)
        ++minpos;
    
    cout << minpos << " " << fpow(1 << 17, m2 - 2, m2, arr2[minpos]) << "\n";
    
    
    return 0;
}