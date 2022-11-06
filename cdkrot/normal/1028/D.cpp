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

const int mod = 1000 * 1000 * 1000 + 7;

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int T = input<int>();
    int64_t ans = 1;

    set<int> buy, any, sell;
    
    for (int z = 0; z != T; ++z) {
        if (input<string>() == "ADD") {
            int val = input<int>();

            if (not buy.empty() and val < (*buy.rbegin()))
                buy.insert(val);
            else if (not sell.empty() and val > (*sell.begin()))
                sell.insert(val);
            else
                any.insert(val);
        } else {
            int val = input<int>();
            
            if (buy.count(val)) {
                if (val != (*buy.rbegin())) {
                    goto fi;
                }

                buy.erase(val);
            } else if (sell.count(val)) {
                if (val != (*sell.begin())) {
                    goto fi;
                }

                sell.erase(val);
            } else {
                assert(any.count(val));
                ans *= 2;
                ans %= mod;

                any.erase(val);
            }
            
            for (auto elem: any)
                if (elem < val)
                    buy.insert(elem);
                else
                    sell.insert(elem);
            
            any.clear();
        }
    }

    ans *= (SZ(any) + 1);
    ans %= mod;
    cout << ans << "\n";
    return 0;

fi:;
    cout << "0\n";
    return 0;
}