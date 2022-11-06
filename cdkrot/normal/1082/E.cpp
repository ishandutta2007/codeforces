// 2018, Sayutin Dmitry.

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

#define pb push_back
#define eb emplace_back

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    int c = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    vector<int> csum(n + 1);
    for (int i = 0; i != n; ++i)
        if (a[i] == c)
            csum[i + 1] = 1;

    for (int i = 1; i <= n; ++i)
        csum[i] += csum[i - 1];

    int ccnt = csum.back();
    
    map<int, vector<int>> indices;
    for (int i = 0; i != n; ++i)
        indices[a[i]].push_back(i);

    int ans = ccnt;
    for (auto el: indices) {
        if (el.first == c)
            continue;
        
        vector<int> data;

        for (int i = 0; i != SZ(el.second); ++i) {
            if (i)
                data.push_back(-(csum[el.second[i]] - csum[el.second[i - 1] + 1]));
            
            data.push_back(1);
        }

        int cur = 0;
        for (int val: data) {
            cur += val;

            if (cur < 0)
                cur = 0;

            ans = max(ans, ccnt + cur);
        }
    }

    cout << ans << "\n";
    
    return 0;
}