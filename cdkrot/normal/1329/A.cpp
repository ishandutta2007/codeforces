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
#define int int64_t
    int n, m;
    cin >> n >> m;

    vector<int> arr(m);
    input_seq(ALL(arr));

    int64_t sm = 0;
    for (int x: arr)
        sm += x;

    if (sm < n) {
        cout << "-1\n";
        return 0;
    }

    reverse(ALL(arr));
    
    vector<int> off(m);
    off[0] = 0;
    for (int i = 1; i < m; ++i)
        off[i] = max((int64_t)0, off[i - 1] + arr[i - 1] + 1 - arr[i]);

    if (off.back() + arr.back() > n) {
        cout << "-1\n";
        return 0;
    }

    int i = m - 1;
    int cur_end = n;
    while (i >= 0) {
        int nw = cur_end - arr[i];
        if (nw > off[i])
            off[i] = nw, cur_end = nw, --i;
        else
            break;
    }

    reverse(ALL(off));
    
    for (int x: off)
        cout << x + 1 << " ";
    cout << "\n";
    

    return 0;
}