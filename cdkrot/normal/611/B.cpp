// Copyright (C) 2015-16 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <map>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <utility>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::set;

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

uint64_t f(uint64_t a) {
    /* num of '1' before '0' */
    uint32_t ans = 0;
    for (uint32_t pref_len = 0; pref_len != 64; ++pref_len) {
        for (uint32_t suf_len = 1; suf_len != 64; ++suf_len) {
            if (pref_len + suf_len + 1 <= 63) {
                uint64_t one = 1;
                uint64_t p1 = (one << suf_len) - 1;
                uint64_t p2 = (one << pref_len) - 1;
                uint64_t num = (p1 << (pref_len + 1)) | p2;
                
                if (num <= a) {
#ifdef LOCAL
                    cerr << num << "\n";
#endif
                    ++ans;
                }
            }
        }
    }
    cerr << "\n";
    return ans;
}

int main() {
    uint64_t a, b;
    cin >> a >> b;
    cout << f(b) - f(a - 1) << "\n";
    return 0;
}