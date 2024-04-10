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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n;
    cin >> n;
    
    vector<int> rr(n), cc(n);

    for (int i = 0; i != n; ++i)
        rr[i] = input<int>() - 1;

    for (int i = 0; i != n; ++i)
        cc[i] = input<int>() - 1;
    
    vector<tuple<int, int, int, int>> ans;

    for (int i = 0; i != n; ++i) {
        int r = std::find(ALL(rr), i) - rr.begin();
        int c = std::find(ALL(cc), i) - cc.begin();

        if (r == i and c == i)
            continue;
        
        ans.emplace_back(i + 1, c + 1,
                         r + 1, i + 1);

        swap(rr[i], rr[r]);
        swap(cc[i], cc[c]);
    }
    
    cout << SZ(ans) << "\n";
    for (auto& elem: ans)
        cout << get<0>(elem) << " " << get<1>(elem) << " " << get<2>(elem) << " " << get<3>(elem) << "\n";
    
    return 0;
}