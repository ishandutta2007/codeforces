// Dmitry _kun_ Sayutin (2020)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

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

struct dsu_t {
    vector<int> par;

};

struct edge_t {
    int a;
    int b;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<int> arr(2 * n);
    input_seq(ALL(arr));
    
    auto work = [&](int mi, bool print_ans = false) {
        cc_hash_table<int, int> compid;
        cc_hash_table<int, int> parity;

        vector<edge_t> edges;
        vector<vector<int>> go;

        for (int i = 0; i < 2 * n; i += 2) {
            int a = arr[i] & ((1 << mi) - 1);
            int b = arr[i + 1] & ((1 << mi) - 1);

            parity[a] ^= 1;
            parity[b] ^= 1;

            if (compid.find(a) == compid.end()) {
                compid[a] = SZ(go); go.resize(SZ(go) + 1);
            }
            if (compid.find(b) == compid.end()) {
                compid[b] = SZ(go); go.resize(SZ(go) + 1);
            }
            
            a = compid[a], b = compid[b];
            
            int id = i / 2;
            edges.emplace_back(edge_t {a, b});

            go[a].push_back(id);
            go[b].push_back(id);
        }

        for (auto elem: parity)
            if (elem.second)
                return false;

        vector<char> is_reached(SZ(go), false);
        vector<int> queue = {0};
        is_reached[0] = true;
        
        for (int p = 0; p < SZ(queue); ++p) {
            for (int eid: go[queue[p]]) {
                int to = edges[eid].a + edges[eid].b - queue[p];

                if (not is_reached[to])
                    is_reached[to] = true, queue.push_back(to);
            }
        }

        if (SZ(queue) != SZ(go))
            return false;
        
        if (not print_ans)
            return true;

        vector<pair<int, int>> walk;
        vector<char> edge_used(n, false);
        vector<int> ptr(SZ(go), 0);
        
        std::function<void(int)> traverse = [&](int v) {
            int& p = ptr[v];
            while (p != SZ(go[v])) {
                int eid = go[v][p++];

                if (not edge_used[eid]) {
                    edge_used[eid] = true;
                    
                    int to = edges[eid].a + edges[eid].b - v;
                    traverse(to);
                    
                    int to_index = 2 * eid + (to == compid[arr[2 * eid] & ((1 << mi) - 1)] ? 0 : 1);
                    int from_index = to_index ^ 1;
                    cout << to_index + 1 << " " << from_index + 1 << " ";
                }
            }
        };

        traverse(0);
        
        return true;
    };

    int lo = 0; // okay
    int hi = 21; //not okay

    while (hi - lo > 1) {
        auto mi = lo + (hi - lo) / 2;

        if (work(mi))
            lo = mi;
        else
            hi = mi;
    }

    cout << lo << "\n";
    work(lo, true);
    cout << "\n";
    
    return 0;
}