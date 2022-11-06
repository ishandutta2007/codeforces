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

#define int int64_t

struct line {
    int k;
    int64_t b;
};

double compare(line a, line b) {
    int K = a.k - b.k;
    int64_t B = a.b - b.b;

    // kx + b == 0
    
    return double(-B) / K;
}

int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<int> arr(n);
    input_seq(ALL(arr));

    vector<int64_t> sums(n + 1);
    for (int i = 1; i <= n; ++i)
        sums[i] = sums[i - 1] + arr[i - 1];
    
    vector<line> hull;
    vector<double> better_from;

    vector<int> L(n);
    for (int i = 0; i <= n; ++i) {
        line my = {-i, sums[i]};
        while (not hull.empty()) {
            auto bt = compare(hull.back(), my);
            if (bt < better_from.back())
                hull.pop_back(), better_from.pop_back();
            else
                break;
        }

        if (i != 0) {
            assert(not better_from.empty());
            L[i - 1] = -hull.back().k;
        }
        
        better_from.push_back(hull.empty() ? 0.0 : compare(hull.back(), my));
        hull.push_back(my);
    }

    vector<double> ans(n);
    for (int i = n - 1; i >= 0;) {
        int l = L[i];

        auto sm = std::accumulate(arr.begin() + l, arr.begin() + i + 1, int64_t(0));
        for (int p = l; p <= i; ++p)
            ans[p] = double(sm) / (i - l + 1);

        i = l - 1;
    }

    cout << std::fixed;
    cout.precision(10);
    for (double el: ans)
        cout << el << "\n";

    return 0;
}