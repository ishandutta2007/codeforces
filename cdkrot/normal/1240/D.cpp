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
    for (int q= input<int>(); q != 0; --q) {
        int n = input<int>();
        vector<int> a(n);
        input_seq(ALL(a));

        const int inf = 2 * n;
        vector<int> nxt(n, inf);

        vector<map<int, int>> mps(n);
        mps[n - 1][a[n - 1]] = n - 1;
        
        for (int i = n - 2; i >= 0; --i) {
            if (mps[i + 1].count(a[i]))
                nxt[i] = mps[i + 1][a[i]];

            if (nxt[i] != inf and nxt[i] != n - 1) {
                mps[i] = std::move(mps[nxt[i] + 1]);
            }

            mps[i][a[i]] = i;
        }

        vector<int> len(n + 3, 0);
        for (int i = n - 1; i >= 0; --i)
            if (nxt[i] != inf)
                len[i] = 1 + len[nxt[i] + 1];

        cout << std::accumulate(ALL(len), int64_t(0)) << "\n";
    }

    return 0;
}