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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    uint64_t m = input<uint64_t>();
    uint64_t lo = 7; // f(lo) < m.
    uint64_t hi = 8 * m + 1; // f(hi) >= m

    while (hi - lo > 1) {
        uint64_t mi = lo + (hi - lo) / 2;
        uint64_t f = 0;
        for (uint64_t i = 2; (mi / i / i / i) >= 1; ++i)
            f += mi / i / i / i;
        if (f >= m)
            hi = mi;
        else
            lo = mi;
    }
    uint64_t f = 0;
    for (uint64_t i = 2; (hi / i / i / i) >= 1; ++i)
        f += hi / i / i / i;
    if (f != m)
        cout << "-1\n";
    else
        cout << hi << "\n";

    /*    f = 0;
    for (uint64_t i = 2; (8 / i / i / i) >= 1; ++i)
        f += 8 / i / i / i;
        cout << f << "\n"; */
    
    return 0;
}