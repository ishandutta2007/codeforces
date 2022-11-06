// Dmitry _kun_ Sayutin (2019)

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

int p = 29;
int64_t mod = (1000 * 1000 * 1000 + 7) * int64_t(1000 * 1000 * 1000 + 9);

int64_t add(int64_t a, int64_t b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int64_t sub(int64_t a, int64_t b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int64_t mult(uint64_t a, uint64_t b) { // thanks Mike for modern judge
    uint64_t k = (long double)a * b / mod;

    uint64_t res = a * b - k * mod;
    int64_t rr = res;

    if (rr < 0)
        rr += mod;
    if (rr >= mod)
        rr -= mod;

    return rr;
}

struct quer_t {
    int qid;
    int sign;
    bool is_rev;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();

    vector<vector<pair<int, char>>> graph(n);
    for (int i = 1; i < n; ++i) {
        int v, u;
        char c;

        cin >> v >> u >> c;
        --v, --u;
        
        graph[v].emplace_back(u, c);
        graph[u].emplace_back(v, c);
    }

    int LOG = 0;
    while ((1 << LOG) < n)
        ++LOG;
    
    vector<int> depth(n, -1);
    vector<vector<int>> up(LOG + 1, vector<int>(n));
    vector<char> par_let(n, -1);
    
    std::function<void(int, int)> dfs = [&](int v, int p) {
        depth[v] = (p == v ? 0 : depth[p] + 1);
        up[0][v] = p;

        for (int i = 1; i <= LOG; ++i)
            up[i][v] = up[i - 1][up[i - 1][v]];

        for (auto u: graph[v])
            if (u.first != p)
                dfs(u.first, v);
            else
                par_let[v] = u.second;
    };

    dfs(0,0);

    auto la = [&](int v, int k) {
        for (int i = LOG; i >= 0; --i)
            if (k & (1 << i))
                v = up[i][v];

        return v;
    };

    auto lca = [&](int v, int u) {
        if (not (depth[v] >= depth[u]))
            swap(v, u);

        v = la(v, depth[v] - depth[u]);
        if (v == u)
            return v;

        for (int i = LOG; i >= 0; --i)
            if (up[i][v] != up[i][u])
                v = up[i][v], u = up[i][u];

        return up[0][v];
    };

    int Q = input<int>();
    vector<string> quer(Q);
    vector<int> ans(Q);
    vector<int64_t> fhash(Q), rhash(Q);

    gp_hash_table<int64_t, int> interesting;
    
    vector<vector<quer_t>> queries(n);
    for (int i = 0; i < Q; ++i) {
        int v, u;
        cin >> v >> u >> quer[i];
        --v, --u;

        int64_t& wanthash = fhash[i];
        int64_t& want_rhash = rhash[i];
        for (char c: quer[i])
            wanthash = add(mult(29, wanthash), c);

        for (int t = SZ(quer[i]) - 1; t >= 0; --t)
            want_rhash = add(mult(29, want_rhash), quer[i][t]);
        
        int L = lca(v, u);
        int len1 = depth[v] - depth[L];
        int len2 = depth[u] - depth[L];

        int v0 = v, u0 = u;
        
        if (len1 > SZ(quer[i])) {
            queries[v].emplace_back(quer_t {i, +1, false});
            queries[v0 = la(v, len1 - SZ(quer[i]))].emplace_back(quer_t {i, -1, false});

            interesting[rhash[i]] = 0;
        }

        if (len2 > SZ(quer[i])) {
            queries[u].emplace_back(quer_t {i, +1, true});
            queries[u0 = la(u, len2 - SZ(quer[i]))].emplace_back(quer_t {i, -1, true});

            interesting[fhash[i]] = 0;
        }

        string pain;
        for (int vert = v0; vert != L; vert = up[0][vert])
            pain += par_let[vert];

        string p2;
        for (int vert = u0; vert != L; vert = up[0][vert])
            p2 += par_let[vert];

        std::reverse(ALL(p2));
        pain = quer[i] + '$' + pain + p2;

        vector<int> pi(SZ(pain), 0);
        for (int i = 1; i < SZ(pain); ++i) {
            int k = pi[i - 1];
            
            while (k != -1 and pain[i] != pain[k])
                k = (k == 0 ? -1 : pi[k - 1]);

            pi[i] = k + 1;
        }

        for (int val: pi)
            if (val == SZ(quer[i]))
                ++ans[i];
    }

    vector<int64_t> pows(n + 1, 1);
    for (int i = 1; i <= n; ++i)
        pows[i] = mult(p, pows[i - 1]);
    
    gp_hash_table<int64_t, int> count;

    vector<int64_t> curhash = {0};
    
    std::function<void(int)> go = [&](int v) {
        for (auto que: queries[v]) {
            auto wanthash = (not que.is_rev ? rhash[que.qid] : fhash[que.qid]);            

            auto it = interesting.find(wanthash);
            if (true or it != count.end())
                ans[que.qid] += que.sign * (it->second);
        }
        
        for (auto u: graph[v])
            if (depth[u.first] > depth[v]) {
                curhash.push_back(add(mult(curhash.back(), p),
                                      u.second));

                for (int len = 1; len <= min(SZ(curhash) - 1, 100); ++len) {
                    int64_t hs = sub(curhash.back(), mult(curhash[SZ(curhash) - 1 - len], pows[len]));

                    auto it = interesting.find(hs);
                    if (it != interesting.end())
                        ++(it->second);
                }
                
                go(u.first);

                for (int len = 1; len <= min(SZ(curhash) - 1, 100); ++len) {
                    int64_t hs = sub(curhash.back(), mult(curhash[SZ(curhash) - 1 - len], pows[len]));

                    auto it = interesting.find(hs);
                    if (it != interesting.end())
                        --(it->second);
                }
                
                curhash.pop_back();
            }
    };

    go(0);

    for (auto elem: ans)
        cout << elem << "\n";
    
    return 0;
}