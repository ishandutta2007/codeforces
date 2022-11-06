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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(n), B(m);
    for (int i = 0; i < n; ++i)
        cin >> A[i].first >> A[i].second;

    for (int j = 0; j < m; ++j)
        cin >> B[j].first >> B[j].second;
    
    vector<pair<int, int>> events;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int dx = max(0, B[j].first - A[i].first + 1);
            int dy = max(0, B[j].second - A[i].second + 1);

            events.emplace_back(dx, dy);
        }

    sort(ALL(events));
    int ans = TYPEMAX(int);
    int min_y = 0;

    for (int i = SZ(events) - 1; i >= 0; --i) {
        ans = min(ans, events[i].first + min_y);
        min_y = max(min_y, events[i].second);
    }

    ans = min(ans, min_y);
    cout << ans << "\n";
    
    return 0;
}