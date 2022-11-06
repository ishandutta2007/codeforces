// Dmitry _kun_ Sayutin (2019)

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,std::less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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

struct quer_t {
    int qbase;
    int sign;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n, k;
    cin >> n >> k;

    vector<tuple<int, int, int>> fuck(n);
    for (int i = 0; i < n; ++i) {
        cin >> get<0>(fuck[i]) >> get<1>(fuck[i]) >> get<2>(fuck[i]);
    }
    
    sort(ALL(fuck));
    
    vector<int> sucks;
    for (auto go: fuck)
        sucks.emplace_back(get<2>(go));
    sort(ALL(sucks));
    sucks.resize(std::unique(ALL(sucks)) - sucks.begin());
       
    int Q = SZ(sucks);

    ordered_set<pair<int, int>> alive_by_x[Q];
    set<pair<int, int>> ttd;
    
    int64_t ans = 0;

    for (int i = 0; i < n; ++i) {
        int x = get<0>(fuck[i]);
        int r = get<1>(fuck[i]);
        int& qq = get<2>(fuck[i]);
        qq = std::lower_bound(ALL(sucks), qq) - sucks.begin();

        while (not ttd.empty() and ttd.begin()->first <= x) {
            int die = ttd.begin()->second;
            alive_by_x[get<2>(fuck[die])].erase(make_pair(get<0>(fuck[die]), die));
            
            ttd.erase(ttd.begin());
        }

        int A = qq;
        while (A >= 1 and sucks[A - 1] >= sucks[qq] - k)
            --A;
        int B = qq;
        while (B + 1 < SZ(sucks) and sucks[B + 1] <= sucks[qq] + k)
            ++B;

        for (int v = A; v <= B; ++v) {
            ans += SZ(alive_by_x[v]) - alive_by_x[v].order_of_key(make_pair(x - r, -100));
        }

        alive_by_x[qq].insert(make_pair(x, i));
        ttd.emplace(x + r + 1, i);
    }

    cout << ans << "\n";
    
    return 0;
}