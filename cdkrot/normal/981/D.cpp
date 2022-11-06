// Copyright (C) 2018 Sayutin Dmitry.
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


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int k = input<int>();

    vector<int64_t> a(n);
    input_seq(ALL(a));

    vector<int64_t> psums(n + 1);
    for (int i = 0; i != n; ++i)
        psums[i + 1] = psums[i] + a[i];
    
    auto ok = [&](int64_t c) {
        
        vector<vector<char>> dp(k, vector<char>(n));

        for (int i = 0; i != n; ++i)
            if ((psums[i + 1] & c) == c)
                dp[0][i] = 1;

        for (int lvl = 1; lvl != k; ++lvl)
            for (int i = 1; i != n; ++i)
                for (int prev = 0; prev != i; ++prev)
                    if (((psums[i + 1] - psums[prev + 1]) & c) == c)
                        dp[lvl][i] or_eq dp[lvl - 1][prev];

        return dp.back().back();
    };
    
    int64_t ans = 0;
    for (int64_t bt = 62; bt >= 0; --bt) {
        int64_t nans = ans | (int64_t(1) << bt);

        if (ok(nans))
            ans = nans;
    }

    cout << ans << "\n";
    
    return 0;
}