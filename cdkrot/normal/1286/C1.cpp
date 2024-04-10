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

    auto read = [&](int l, int r) {
        cout << "? " << l + 1 << " " << r + 1 << std::endl;

        vector<string> rs;
        int len = (r - l + 1);
        int cnt = (len) * (len + 1) / 2;

        for (int i = 0; i < cnt; ++i) {
            string s = input<string>();
            sort(ALL(s));
            rs.push_back(s);
        }

        sort(ALL(rs));
        return rs;
    };
    
    if (n == 1) { // thanks
        auto rs = read(0, 0)[0];
        cout << "! " << rs << std::endl;
    } else {    
        vector<string> set1 = read(0, n - 1);
        vector<string> set2 = read(1, n - 1);

        vector<string> res;
        std::set_difference(ALL(set1), ALL(set2), std::inserter(res, res.begin()));

        sort(ALL(res), [&](string a, string b) {
            return SZ(a) < SZ(b);
        });

        string ans;
        for (string s: res) {
            string x = ans;

            std::sort(ALL(x));
            std::sort(ALL(s));

            std::set_difference(ALL(s), ALL(x), std::inserter(ans, ans.end()));
        }

        cout << "! " << ans << std::endl;
    }
    return 0;
}