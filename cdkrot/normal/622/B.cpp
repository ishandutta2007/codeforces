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

    auto str = input<string>();
    uint32_t delta = input<uint32_t>();

    assert(str.size() == 5 and str[2] == ':');
    uint32_t hrs = 10 * (str[0] - '0') + str[1] - '0';
    uint32_t mns = 10 * (str[3] - '0') + str[4] - '0';
    uint32_t tm = (60 * hrs + mns + delta) % (24 * 60);

    hrs = tm / 60;
    mns = tm % 60;
    string res = "--:--";
    res[0] = '0' + (hrs / 10), res[1] = '0' + (hrs % 10), res[3] = '0' + (mns / 10), res[4] = '0' + (mns % 10);
    cout << res << "\n";
    return 0;
}