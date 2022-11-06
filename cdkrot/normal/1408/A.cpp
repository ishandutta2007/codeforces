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
    for (int t = input<int>(); t; --t) {
        int n;
        cin >> n;

        vector<array<int, 3>> arr(n);

        for (int j = 0; j < 3; ++j)
            for (int i = 0; i < n; ++i)
                cin >> arr[i][j];

        vector<int> ans(n);
        ans[0] = arr[0][0];

        for (int i = 1; i < n; ++i) {
            int j = 0;
            while (arr[i][j] == ans[i - 1] or (i + 1 == n and arr[i][j] == ans[0]))
                ++j;

            ans[i] = arr[i][j];
        }

        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;
}