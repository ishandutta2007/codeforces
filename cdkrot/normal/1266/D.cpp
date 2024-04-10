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
    int n, m;
    cin >> n >> m;

    vector<map<int, int64_t>> out(n), in(n);
    auto increase = [&](int v, int u, int64_t w) {
        //cerr << v << " " << u << " " << w << "!\n";
        if (v == u)
            return;
        
        if (out[v].count(u)) {
            w += out[v][u];
            out[v].erase(u);
        }

        if (out[u].count(v)) {
            w -= out[u][v];
            out[u].erase(v);
        }

        in[v].erase(u);
        in[u].erase(v);
        
        if (w == 0)
            return;

        if (w < 0)
            swap(v, u), w = -w;
        
        in[u][v] += w;
        out[v][u] += w;
    };
    
    for (int i = 0; i < m; ++i) {
        int v, u, w;
        cin >> v >> u >> w;
        --v, --u;

        increase(v, u, w);
    }

    queue<int> q;
    vector<char> inqueue(n, true);
    for (int i = 0; i < n; ++i)
        q.push(i);

    while (not q.empty()) {
        int v = q.front();
        q.pop();
        
        while (true) {
            if (out[v].empty() or in[v].empty())
                break;

            auto A = in[v].begin()->first;
            auto Aw = in[v].begin()->second;

            auto B = out[v].begin()->first;
            auto Bw = out[v].begin()->second;
        
            auto w = min(Aw, Bw);

            //cerr << "ABW " << A << " " << B << " " << w << "\n";
            increase(A, B, w);
            increase(A, v, -w);
            increase(v, B, -w);

            if (not inqueue[A])
                inqueue[A] = 1, q.push(A);
            if (not inqueue[B])
                inqueue[B] = 1, q.push(B);

        }
    }

    vector<tuple<int, int, int64_t>> res;
    for (int v = 0; v < n; ++v)
        for (auto elem: out[v])
            res.emplace_back(v, elem.first, elem.second);

    cout << SZ(res) << "\n";
    for (auto elem: res)
        cout << get<0>(elem) + 1 << " " << get<1>(elem) + 1 << " " << get<2>(elem) << "\n";
    
    return 0;
}