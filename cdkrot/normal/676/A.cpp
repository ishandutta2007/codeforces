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

    vector<uint32_t> arr(input<uint32_t>());
    std::generate(arr.begin(), arr.end(), input<uint32_t>);

    uint32_t st = UINT32_MAX, en = UINT32_MAX;
    for (uint32_t i = 0; i != arr.size(); ++i) {
        if (arr[i] == 1)
            st = i;
        if (arr[i] == arr.size())
            en = i;
    }

    assert(max(st, en) != UINT32_MAX);

    // if n <= 3.
    uint32_t best = max(max(st - 0, (uint32_t)arr.size() - 1 - st), max(en - 0, (uint32_t)arr.size() - 1 - en));
        best = max(best, max(en, st) - min(en, st));

    cout << best << "\n";
    
    
    return 0;
}