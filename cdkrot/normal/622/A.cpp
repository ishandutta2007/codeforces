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

    uint64_t pos = input<uint64_t>();

    uint64_t l = 1; /* block we definitely in or later */
    uint64_t r = 1000 * 1ull * 1000 * 1ull * 100;

    while (r - l > 1) {
        auto mid = l + (r - l) / 2;
        if ((mid * (mid - 1)) / 2 < pos)
            l = mid;
        else
            r = mid;
    }
    cout << pos - (l * (l - 1) / 2) << "\n";
    return 0;
}