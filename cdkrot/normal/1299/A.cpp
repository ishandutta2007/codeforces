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
    vector<int> arr(n);
    input_seq(ALL(arr));

    vector<int> pref(n + 1), suf(n + 1);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] | arr[i - 1];

    for (int i = n - 1; i >= 0; --i)
        suf[i] = suf[i + 1] | arr[i];

    int ans = -1;
    int pbest = -1;
    for (int i = 0; i < n; ++i) {
        int cost = arr[i] & ~(pref[i] | suf[i + 1]);

        if (cost > ans)
            ans = cost, pbest = i;
    }

    std::swap(arr[pbest], arr[0]);
    for (int elem: arr)
        cout << elem << " ";
    cout << "\n";
    
    return 0;
}