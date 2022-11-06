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

#define int int64_t

int64_t cross(pair<int, int> a, pair<int, int> b) {
    return int64_t(a.first) * b.second - int64_t(a.second) * b.first;
}

pair<int, int> sub(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<pair<int, int>> coords(n);

    for (int i = 0; i != n; ++i) {
        cin >> coords[i].first >> coords[i].second;
    }

    string s = input<string>();

    vector<char> used(n);
    
    int start = std::min_element(ALL(coords)) - coords.begin();

    vector<int> ans = {start};
    used[start] = 1;

    for (int it = 0; it != n - 2; ++it) {
        int optimal = -1;
        
        for (int i = 0; i != n; ++i)
            if (not used[i])
                if (optimal == -1 or cross(sub(coords[i], coords[ans.back()]), sub(coords[optimal], coords[ans.back()])) * (s[it] == 'L' ? +1 : -1) > 0)
                    optimal = i;

        ans.push_back(optimal);
        used[optimal] = 1;
    }

    for (int i = 0; i != n; ++i)
        if (not used[i])
            ans.push_back(i);
    
    for (int elem: ans)
        cout << elem + 1 << " ";
    cout << "\n";
    
    return 0;
}