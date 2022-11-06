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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n, k, q;
    cin >> n >> k >> q;

    vector<uint32_t> levels(n);
    std::generate(levels.begin(), levels.end(), input<uint32_t>);

    set<uint32_t> cur;
    for (uint32_t i = 0; i != q; ++i) {
        auto t = input<char>();
        uint32_t id = input<uint32_t>() - 1;

        if (t == '2') {
            string res[2] = {"NO\n", "YES\n"};
            cout << res[cur.find(levels[id]) != cur.end()];
        } else {
            cur.insert(levels[id]);
            if (cur.size() > k)
                cur.erase(cur.begin());
        }
    }
    
    return 0;
}