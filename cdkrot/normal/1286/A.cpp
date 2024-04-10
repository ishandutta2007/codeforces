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

// prefix, numEven, curParity
int dp[105][105][3];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<char> used(n + 1);
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i])
            used[arr[i]] = 1;
    }

    for (int i = 0; i < 105; ++i)
        for (int j = 0; j < 105; ++j)
            for (int t = 0;  t < 3; ++t)
                dp[i][j][t] = TYPEMAX(int) / 3;

    dp[0][0][2] = 0;
    for (int i = 0; i < n; ++i) {
        for (int curParity = 0; curParity < 2; ++curParity) {
            if (arr[i] and curParity != arr[i] % 2)
                continue;
            
            for (int prevEven = 0; prevEven < 105; ++prevEven)
                for (int prevParity = 0; prevParity <= 2; ++prevParity) {
                    dp[i + 1][prevEven + 1 - curParity][curParity] = min(dp[i + 1][prevEven + 1 - curParity][curParity],
                                                                     dp[i][prevEven][prevParity] + int (curParity != prevParity and prevParity != 2));
                }
        }
    }

    int ans = 100000;
    ans = min({ans, dp[n][n/2][0], dp[n][n/2][1]});
    cout << ans << "\n";
    
    return 0;
}