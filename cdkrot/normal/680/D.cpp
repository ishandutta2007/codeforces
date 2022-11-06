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

template <typename T>
T cube(T a) {
    return a * a * a;
}

pair<int64_t, int64_t> solve(int64_t maxx, int64_t maxblock) {
    if (maxx < 0 or maxblock < 0)
        return make_pair(-1, -1);
    if (maxx == 0)
        return make_pair(0, 0);

    while (cube(maxblock) > maxx)
        --maxblock;
    
    auto sol1 = solve(maxx - cube(maxblock), maxblock);
    auto sol2 = solve(min(maxx - cube(maxblock - 1), cube(maxblock) - 1 - cube(maxblock - 1)), maxblock - 1);

    if (sol1.first != -1)
        sol1.first += 1, sol1.second += cube(maxblock);
    
    if (sol2.first != -1)
        sol2.first += 1, sol2.second += cube(maxblock - 1);
    return max(sol1, sol2);
}

int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int64_t m = input<int64_t>();
    auto sol = solve(m, 100 * 1000 + 1);
    cout << sol.first << " " << sol.second << "\n";
    
    return 0;
}