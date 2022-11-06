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

// zeros, ones.
pair<int64_t, int64_t> get(int64_t x) {
    static std::map<int64_t, pair<int64_t, int64_t>> memo;

    if (memo.find(x) != memo.end())
        return memo.find(x)->second;

    if (x == 0)
        return {1, 0};
    if (x == 1)
        return {0, 1};

    auto sub = get(x / 2);
    sub.first *= 2, sub.second *= 2;
    
    if (x % 2 == 0)
        sub.first += 1;
    else
        sub.second += 1;

    return memo[x] = sub;
}

bool intersects(int64_t a, int64_t b, int64_t c, int64_t d) {
    return max(a, c) <= min(b, d);
}

int64_t get_ans(int64_t num, int64_t l, int64_t r) {
    auto dp = get(num);
    if (l <= 0 and  dp.first + dp.second - 1 <= r)
        return dp.second;

    auto subdp = get(num / 2);
    int64_t ans = 0;
    if (intersects(0, subdp.first + subdp.second - 1, l, r))
        ans += get_ans(num / 2, l, r);
    if (intersects(subdp.first + subdp.second, subdp.first + subdp.second, l, r))
        ans += num % 2;
    if (intersects(subdp.first + subdp.second + 1, 2 * subdp.first + 2 * subdp.second, l, r))
        ans += get_ans(num / 2, l - (subdp.first + subdp.second + 1), r - (subdp.first + subdp.second + 1));
    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int64_t n, l, r;
    cin >> n >> l >> r;
    l -= 1, r -= 1;
    
    cout << get_ans(n, l, r) << "\n";

    return 0;
}