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
#include <functional>
#include <utility>
#include <string>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
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


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int64_t> data(input<uint32_t>());
    std::generate(data.begin(), data.end(), input<int32_t>);

    std::sort(data.begin(), data.end());
    std::reverse(data.begin(), data.end());
    int64_t ans = 0;
    int64_t mx = INT64_MAX;

    for (auto v: data) {
        if (min(mx, v) < 0)
            break;
        ans += min(mx, v);
        mx = min(mx, v) - 1;
    }
    cout << ans << "\n";
    return 0;
}