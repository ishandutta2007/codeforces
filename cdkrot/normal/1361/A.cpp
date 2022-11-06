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

    vector<vector<int>> go(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b; --a, --b;

        go[a].push_back(b);
        go[b].push_back(a);
    }

    vector<int> col(n);
    
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; ++i)
        data[i] = make_pair(col[i] = input<int>() - 1, i);
    sort(ALL(data));

    for (auto x: data) {
        int v = x.second;
        vector<char> used(col[v] + 1);

        for (int u: go[v])
            if (col[u] <= col[v])
                used[col[u]] = true;

        if (std::find(ALL(used), false) != used.end() - 1) {
            cout << "-1\n";
            return 0;
        }
    }

    for (auto x: data)
        cout << 1 + x.second << " ";
    cout << "\n";

    return 0;
}