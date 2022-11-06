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

const uint32_t mx = 512;

void add(vector<vector<uint32_t>>& water, uint32_t i, uint32_t j, uint32_t w) {
    uint32_t transf = min(mx - water[i][j], w);
    water[i][j] += transf;        
    w -= transf;
    if (w != 0) {
        if (i + 1 < water.size()) {
            assert(w % 2 == 0);
            add(water,i + 1, j, w / 2), add(water ,i + 1, j + 1, w / 2);
        }
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n, t;
    cin >> n >> t;

    vector<vector<uint32_t>> water(n);
    for (uint32_t i = 0; i != n; ++i) {
        water[i].resize(i + 1, 0);
    }

    for (uint32_t tm = 1; tm <= t; ++tm) {
        add(water, 0, 0, mx);
    }
    uint32_t ans = 0;
    for (const auto& vec: water)
        for (const  uint32_t& v: vec)
            ans += v == mx;
    cout << ans << "\n";
    return 0;
}