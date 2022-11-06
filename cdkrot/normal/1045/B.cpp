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
    int n = input<int>();
    int m = 2 * input<int>();

    vector<int> a(n);
    for (int& elem: a)
        elem = 2 * input<int>();

    vector<int> parts;
    for (int i = 0; i < n; ++i) {
        int x = a[i];
        int y = (i == 0 ? a.back() - m : a[i - 1]);

        parts.push_back((x - y) / 2);
        parts.push_back((x - y) / 2);
    }

    int orig_sz = SZ(parts);
    for (int i = 0; i < 2 * orig_sz; ++i)
        parts.push_back(parts[i]);

    vector<int> mana(3 * orig_sz);
    int L = -1, R = -1;
    for (int i = 1; i < 3 * orig_sz; ++i) {
        if (i <= R)
            mana[i] = min(R - i + 1, mana[R + L - i + 1]);
        
        while (i + mana[i] < SZ(parts) and i - 1 - mana[i] >= 0 and parts[i + mana[i]] == parts[i - 1 - mana[i]])
            ++mana[i];

        if (i + mana[i] - 1 > R) {
            R = i + mana[i] - 1;
            L = i - mana[i];
        }
    }

    vector<int> bad;

    int curval = a.back();
    for (int i = orig_sz; i < 2 * orig_sz; curval += parts[i++])
        if (2 * mana[i] >= orig_sz) {
            //if (curval % 2 == 0)
                bad.push_back((2 * curval) % m);
        }

    sort(ALL(bad));
    bad.resize(std::unique(ALL(bad)) - bad.begin());

    cout << SZ(bad) << "\n";
    for (int x: bad)
        cout << x / 2 << " ";
    cout << "\n";
    
    return 0;
}