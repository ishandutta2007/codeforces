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

const int max_k = 19;
const int max_n = 300 * 1000 + 10;

// int n;
// int in[max_n];
// int color[max_n][max_k];

// vector<int> graph_fwd[max_n], graph_bck[max_n];

// void add_edge(int v, int u) {
//     graph_fwd[v].push_back(u);
//     graph_bck[u].push_back(v);
// }

// void dfs(int v, int k, int C) {
//     color[v][k] = C;

//     if (k > 0)
//         for (int u: graph_bck[v])
//             if (color[u][k - 1] == 0)
//                 dfs(u, k - 1, C);

//     if (k + 1 != max_k)
//         for (int u: graph_fwd[v])
//             if (color[u][k + 1] == 0)
//                 dfs(u, k + 1, C);
// }

struct go_t {
    go_t() {
        std::fill(mask, mask + max_k, 0);

        for (int i = 0; i != max_k; ++i)
            mask[i] |= (1 << i);
    }
    
    int mask[max_k];
};

go_t merge(go_t a, go_t b) {
    go_t res;

    for (int i = 0; i != max_k; ++i)
        for (int j = 0; j != max_k; ++j)
            if (a.mask[i] & (1 << j))
                res.mask[i] |= b.mask[j];

    return res;
}

go_t tree[4 * max_n];
int arr[max_n];

void build(int v, int l, int r) {
    if (l == r - 1) {
        tree[v] = go_t();

        for (int i = 0; i != max_k; ++i)
            if (arr[l] & (1 << i))
                tree[v].mask[i] |= arr[l];
    } else {
        int m = l + (r - l) / 2;

        build(2 * v + 1, l, m);
        build(2 * v + 2, m, r);

        tree[v] = merge(tree[2 * v + 1], tree[2 * v + 2]);
    }
}

void get(int v, int nl, int nr, int l, int r, int& cur_mask) {
    if (l <= nl and nr <= r) {
        int new_mask = cur_mask;
        for (int i = 0; i != max_k; ++i)
            if (cur_mask & (1 << i))
                new_mask |= tree[v].mask[i];

        cur_mask = new_mask;
        return;
    }
    if (nr <= l or r <= nl)
        return;

    int mi = nl + (nr - nl) / 2;
    get(2 * v + 1, nl, mi, l, r, cur_mask);
    get(2 *v + 2, mi, nr, l , r, cur_mask);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, q;
    cin >> n >> q;
    
    input_seq(arr, arr + n);
    build(0, 0, n);
    
    for (int i = 0; i != q; ++i) {
        int v, u;
        cin >> v >> u;
        --v, --u;

        bool yes = 0;

        if (arr[v] == 0 or arr[u] == 0) {}
        else {
            int i = 0;
            while ((arr[v] & (1 << i)) == 0)
                ++i;

            int j = 0;
            while ((arr[u] & (1 << j)) == 0)
                ++j;

            int cur_mask = (1 << i);
            get(0, 0, n, v, u + 1, cur_mask);

            yes = bool((cur_mask & (1 << j)) != 0);
        }

         cout << (yes ? "Shi\n" : "Fou\n");
    }
    
    return 0;
}