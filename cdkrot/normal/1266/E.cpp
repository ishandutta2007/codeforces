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

    vector<int> req(n);
    input_seq(ALL(req));

    int64_t S = std::accumulate(ALL(req), int64_t(0));

    vector<int> cnt(n);

    int64_t bonus = 0;
    
    map<pair<int, int>, int> mp;
    
    for (int q = input<int>(); q != 0; --q) {
        int s, t, u;
        cin >> s >> t >> u;
        --s, --u;
        
        if (mp.count(make_pair(s, t))) {
            int id = mp[make_pair(s, t)];
            mp.erase(make_pair(s, t));

            bonus -= min(req[id], cnt[id]);
            cnt[id]--;
            bonus += min(req[id], cnt[id]);
        }

        if (u != -1) {
            mp[make_pair(s, t)] = u;

            bonus -= min(req[u], cnt[u]);
            cnt[u]++;
            bonus += min(req[u], cnt[u]);
        }

        cout << S - bonus << "\n";
    }

    return 0;
}