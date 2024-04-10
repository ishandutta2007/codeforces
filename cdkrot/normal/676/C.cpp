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

    input<uint32_t>();
    auto k = input<uint32_t>();

    string str = input<string>();
    for (auto& v: str)
        v = v - 'a';
    
    uint32_t ans = 0;
    for (uint32_t z = 0; z != 2; ++z) {
        uint32_t l = 0, r = 0, k_left = k;

        while (r != str.size()) {
            if (str[r] == 0)
                ++r;
            else {
                if (k_left != 0) {
                    --k_left, ++r;
                } else {
                    if (str[l] == 1)
                        ++k_left;
                    ++l;
                }
            }

            if (r >= l)
                ans = max(ans, r - l);
        }
        
        for (auto& v: str)
            v = 1 - v;
    }

    cout << ans << "\n";
    
    return 0;
}