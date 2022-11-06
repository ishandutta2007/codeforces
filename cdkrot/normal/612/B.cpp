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

uint32_t abs(uint32_t a, uint32_t b) {
    return (a >= b ? a - b : b - a);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<uint32_t> arr(input<uint32_t>());
    std::generate(arr.begin(), arr.end(), input<uint32_t>);
    
    vector<uint32_t> inv(arr.size());
    for (uint32_t i = 0; i != arr.size(); ++i)
        inv[arr[i] - 1] = i;
    
    uint64_t ans = 0;
    for (uint32_t i = 1; i != inv.size(); ++i)
        ans += abs(inv[i - 1], inv[i]);
    cout << ans << "\n";
    
    return 0;
}