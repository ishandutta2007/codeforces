// Copyright (C) 2016 Sayutin Dmitry.
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
#include <type_traits>

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

using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define fori(i, n)      for (int i = 0; i != (n); ++i)
#define forir(i, n)     for (int i = (n) - 1; i >= 0; --i)
#define for64(i, n)     for (int64_t i = 0; i != (n); ++i)
#define for64r(i, n)    for (int64_t i = (n) - 1; i >= 0; --i)
#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()

template <typename Iter>
inline void input_arr(Iter b, Iter e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

template <typename func_t>
int lower_bound(int l, int r, const func_t& func, int target) {
    if (l == r or func(l) >= target)
        return l;
    // f(l) = false.
    // f(r) = true.
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (func(m) >= target)
            r = m;
        else
            l = m;
    }
    return r;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> a(input<int>());
    vector<int> b(a.size());

    input_arr(ALL(a));
    input_arr(ALL(b));

    int log_n = 1;
    while ((1 << log_n) < SZ(a))
        ++log_n;

    vector<vector<int>> sparse_a(log_n, vector<int>(a.size()));
    vector<vector<int>> sparse_b(log_n, vector<int>(b.size()));

    vector<int> pre(a.size() + 1);
    
    fori(i, log_n) {
        fori(j, SZ(a))
            sparse_a[i][j] = (i == 0 ? a[j] : max(sparse_a[i - 1][j], sparse_a[i - 1][min(SZ(a) - 1, j + (1 << (i - 1)))]));
        fori(j, SZ(b))
            sparse_b[i][j] = (i == 0 ? b[j] : min(sparse_b[i - 1][j], sparse_b[i - 1][min(SZ(b) - 1, j + (1 << (i - 1)))]));
    }

    fori(i, SZ(a)) {
        pre[i] = (i == 0 ? 0 : pre[i - 1]);
        if ((2 << pre[i]) < i)
            ++pre[i];
    }

    int64_t ans = 0;
    fori(i, SZ(a)) {
        auto func = [&sparse_a, &sparse_b, &pre, i](int j) {
            int len = j - i + 1;
            int lg  = pre[len];
            int st2 = i + len - (1 << lg);
            return max(sparse_a[lg][i], sparse_a[lg][st2]) - min(sparse_b[lg][i], sparse_b[lg][st2]);
        };

        ans += lower_bound(i, SZ(a), func, 1) - lower_bound(i, SZ(a), func, 0);        
    }

    cout << ans << "\n";
    return 0;
}