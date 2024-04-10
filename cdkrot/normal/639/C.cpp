// Copyright (C) 2016 "Time to emerge -e that world".
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
int64_t to_int(T it1, T it2) {
    int64_t res = 0;
    int64_t pow = 1;
    
    for (T it = it1; it != it2; ++it)
        res += pow * (*it), pow *= 2;
    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int32_t n = input<int32_t>() + 1;
    int32_t k = input<int32_t>();
    vector<int32_t> coefficients(n);
    std::generate(coefficients.begin(), coefficients.end(), input<int32_t>);
    
    vector<int64_t> evaled(n);
    for (int32_t i = 0; i != n; ++i)
        evaled[i] = coefficients[i];

    
    for (int32_t i = 0; i != int32_t(evaled.size()); ++i)
        if (evaled[i] >= 2) {
            if (i + 1 == int32_t(evaled.size()))
                evaled.push_back(0);
            
            evaled[i + 1] += evaled[i] / 2;
            evaled[i] %= 2;
        }

    for (int32_t i = 0; i != int32_t(evaled.size()); ++i) {
        if (evaled[i] == -1 and i + 1 == int32_t(evaled.size()))
            break;
        
        if (evaled[i] < 0) {
            int64_t howmuch = (-evaled[i]) / 2 + (-evaled[i]) % 2;
            evaled[i] += 2 * howmuch;

            if ((i + 1) == int32_t(evaled.size()))
                evaled.push_back(0);
            evaled[i + 1] -= howmuch;
        }
    }
    int32_t res = 0;

    while (evaled.size() >= 1 and evaled.back() == 0)
        evaled.pop_back();
    while (evaled.size() >= 2 and evaled.back() == -1 and evaled[evaled.size() - 2] == 1)
        evaled.pop_back(), evaled.back() = -1;
    
    
    assert(not evaled.empty());
    
    for (int32_t i = 0; i != int32_t(min(coefficients.size(), evaled.size())); ++i) {
        if (evaled.size() - 1 - i > 50) {
            if (evaled[i] != 0)
                break;
            continue;
        }

        int64_t newval = coefficients[i] - to_int(evaled.begin() + i, evaled.end());
        if (-k <= newval and newval <= k and (i + 1 != int32_t(coefficients.size()) or newval != 0))
            ++res;
        
        if (evaled[i] != 0)
            break;
    }

    cout << res << "\n";
    return 0;
}