// Copyright (C) 2017 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; version 3

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <array>
#include <queue>
#include <stack>
#include <functional>
#include <utility>
#include <string>
#include <assert.h>
#include <iterator>
#include <cstdint>
#include <cinttypes>
#include <string.h>
#include <random>
#include <numeric>
#include <tuple>


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

int64_t dp[11][65][1024];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    for (int base = 2; base <= 10; ++base) {
        dp[base][0][0] = 1;
        for (int len = 1; len <= 64; ++len)
            for (int mask = 0; mask != (1 << base); ++mask)
                for (int dig = 0; dig != base; ++dig)
                    dp[base][len][mask] += dp[base][len - 1][mask ^ (1 << dig)];
    }

    auto doit = [](int64_t base, int64_t r) {
        vector<int> res;
        while (r != 0)
            res.push_back(r % base), r /= base;
        std::reverse(ALL(res));
        return res;
    };
    auto func = [&](int64_t base, int64_t r) {
        vector<int> f = doit(base, r);
        
        int64_t ans = 0;
        for (int len = 2; len < SZ(f); len += 2)
            for (int last = 1; last != base; ++last)
                ans += dp[base][len - 1][(1 << last)];

        int mask = 0;
        for (int compref = 0; compref < SZ(f); ++compref) {
            for (int dig = (compref == 0 ? 1 : 0); dig < f[compref]; ++dig)
                ans += dp[base][SZ(f) - compref - 1][mask ^ (1 << dig)];

            mask ^= (1 << f[compref]);
        }
        ans += (mask == 0);

        #ifdef LOCAL
        cout << base << " " << r << " -> " << ans << std::endl;
        #endif
        return ans;
    };
    
    for (int q = input<int>(); q != 0; --q) {
        int64_t b, l, r;
        cin >> b >> l >> r;

        int64_t ans = func(b, r);
        if (l != 1)
            ans -= func(b, l - 1);
        cout << ans << "\n";
    }
    
    return 0;
}