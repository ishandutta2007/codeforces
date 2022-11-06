// 2018, Sayutin Dmitry.

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

#define pb push_back
#define eb emplace_back

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    input<int>();

    int cnt_8 = 0, cnt_all = 0;
    for (char ch: input<string>())
        if (ch == '8')
            ++cnt_8;
        else
            ++cnt_all;

    int ans = 0;
    while (true) {
        if (cnt_8 >= 1) {
            --cnt_8;

            int left = 10;
            int tak = min(cnt_all, left);

            left -= tak;
            cnt_all -= tak;

            tak = min(cnt_8, left);
            left -= tak;
            cnt_8 -= tak;

            if (left == 0)
                ++ans;
            else
                break;
        } else {
            break;
        }

    }

    cout << ans << "\n";
    
    return 0;
}