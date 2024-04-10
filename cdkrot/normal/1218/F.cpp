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
    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    input_seq(ALL(x));
    int A = input<int>();

    vector<int> c(n);
    input_seq(ALL(c));

    std::multiset<int> st;
    int64_t ans = 0;
    for (int i = 0; i != n; ++i) {
        st.insert(c[i]);
        
        while (not st.empty() and k < x[i]) {
            k += A;
            ans += *st.begin();
            st.erase(st.begin());
        }

        if (k < x[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << ans << "\n";
    
    return 0;
}