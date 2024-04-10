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
    vector<pair<int, int>> a(n);
    
    for (int i = 0;  i < n; ++i)
        cin >> a[i].first;
    for (int i = 0;  i < n; ++i)
        cin >> a[i].second;

    sort(ALL(a));

    int64_t ans = 0;
    for (int i = 0; i < n;) {
        int64_t cursum = a[i].second;
        std::multiset<int> vals = {a[i].second};
        
        int curval = a[i].first;
        for (++i; i < n and a[i].first == curval; ++i) {
            cursum += a[i].second;
            vals.insert(a[i].second);
        }
        
        while (true) {
            cursum -= *std::prev(vals.end());
            ans += cursum;
            vals.erase(std::prev(vals.end()));

            if (vals.empty())
                break;

            ++curval;
            
            for (; i < n and a[i].first == curval; ++i) {
                cursum += a[i].second;
                vals.insert(a[i].second);
            }
        }         
    }

    cout << ans << "\n";

    return 0;
}