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

bool solve(int k, string s) {
    int balance = 0;
    int free = 0;
    
    for (int rem = 0; rem < k; ++rem) {
        int c1 = 0, c2 = 0;

        for (int pos = rem; pos < SZ(s); pos += k)
            if (s[pos] == '0')
                ++c1;
            else if (s[pos] == '1')
                ++c2;

        if (c1 and c2)
            return false;

        if (c1)
            ++balance;
        else if (c2)
            --balance;
        else
            ++free;
    }

    return k % 2 == 0 and free >= abs(balance);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    vector<string> ans = {"NO\n", "YES\n"};
    for (int t = input<int>(); t; --t) {
        int n, k; string s;
        cin >> n >> k >> s;

        cout << ans[solve(k, s)];
    }

    return 0;
}