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
    int n = input<int>();
    vector<int64_t> in(n);
    input_seq(ALL(in));

    std::sort(RALL(in));
    in.erase(std::find(ALL(in), 0), in.end());
    n = SZ(in);
    
    vector<int> count(60);
    for (auto elem: in)
        for (int64_t i = 0; i != 60; ++i)
            if (elem & (int64_t(1) << i))
                count[i] += 1;

    if (*std::max_element(ALL(count)) >= 3) {
        cout << 3 << "\n";
        return 0;
    }

    assert(SZ(in) <= 120);
    
    const int inf = 300;
    vector<vector<int>> dist(n, vector<int>(n, inf));
    for (int i = 0; i != n; ++i)
        for (int j = i + 1; j != n; ++j)
            if (in[i] & in[j]) {
                dist[i][j] = dist[j][i] = 1;
//                cerr << i << " " << j << std::endl;
            }

    for (int i = 0; i != n; ++i)
        dist[i][i] = 0;
    
    int ans = inf;
    for (int k = 0; k != n; ++k) {
        auto orig = dist;
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j) {
                dist[i][j] = min(dist[i][j], orig[i][k] + orig[k][j]);

                if ((in[i] & in[k]) and (in[j] & in[k]) and k > i and k > j and i != j)
                    ans = min(ans, orig[i][j] + 2);
            }
    }

    cout << (ans == inf ? -1 : ans) << "\n";

    return 0;
}