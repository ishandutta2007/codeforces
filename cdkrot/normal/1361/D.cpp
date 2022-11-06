// Dmitry _kun_ Sayutin (2020)

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
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> pts;

    vector<vector<int>> lists;
    map<pair<int, int>, int> id_of;

    int pzero = -1;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;

        pts.emplace_back(x, y);

        if (x == 0 and y == 0) {
            pzero = i;
            continue;
        }

        int g = std::__gcd(abs(x), abs(y));
        x /= g;
        y /= g;

        if (not id_of.count(make_pair(x, y)))
            id_of[make_pair(x, y)] = SZ(lists), lists.push_back(vector<int> {});

        lists[id_of[make_pair(x, y)]].push_back(i);
    }

    lists.push_back(vector<int> {pzero});

    vector<vector<double>> costs;

    vector<vector<double>> lists_lens;
    
    for (int i = 0; i < SZ(lists); ++i) {
        vector<double> lens;
        for (int ind: lists[i])
            lens.push_back(sqrt(pts[ind].first * 1.0L * pts[ind].first + pts[ind].second * 1.0L * pts[ind].second));

        sort(ALL(lens));

        vector<double> cst = {0};

        for (int cnt = 1; cnt <= min(SZ(lens), k); ++cnt) {
            cst.push_back(cst.back() + (k + 1 - 2 * cnt) * lens[SZ(lens) - cnt]);
        }
        costs.push_back(cst);

        lists_lens.push_back(lens);
    }

    // vector<double> res = {0};
    // for (auto elem: costs) {
    //     vector<double> newres(SZ(res) + SZ(elem) - 1, -1e100);
    //     for (int i = 0; i < SZ(res); ++i)
    //         for (int j = 0; j < SZ(elem); ++j)
    //             newres[i + j] = max(newres[i + j], res[i] + elem[j]);

    //     res = newres;
    // }

    // cerr << res[k] << "\n";
    
    
    vector<double> vec = {};
    for (auto& cst: costs) {
        for (int i = 1; i < SZ(cst); ++i)
            vec.push_back(cst[i] - cst[i - 1]);
    }

    sort(RALL(vec));

    double ans = std::accumulate(vec.begin(), vec.begin() + k, 0.0);

    if (1) {
        int id = 0;
        for (int i = 0; i < SZ(lists); ++i)
            if (SZ(lists[i]) > SZ(lists[id]))
                id = i;

        int num_taken = 0;
        double upd = 0;
        for (int i = 0; i < SZ(lists); ++i)
            if (i != id)
                num_taken += SZ(lists[i]), upd += costs[i].back();

        if (num_taken < k) {
            int rem = k - num_taken;

            for (int A: {k/2, (k + 1) / 2}) {
                double delta_this = 0;
                
                int B = rem - A;

                if (B < 0)
                    continue;
                
                for (int i = 1; i <= A; ++i) {
                    delta_this += (k + 1 - 2 * i) * lists_lens[id][SZ(lists_lens[id]) - i];
                }

                for (int i = 1; i <= B; ++i) {
                    delta_this += (k + 1 - 2 * (A+i)) * lists_lens[id][B - i];
                }

                ans = max(ans, upd + delta_this);
            }
            
        }
    }

    cout << std::fixed;
    cout.precision(10);
    cout << ans << "\n";
    
    return 0;
}