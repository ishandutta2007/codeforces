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

    uint32_t n = input<uint32_t>();
    vector<uint32_t> odd;
    vector<uint32_t> even;
    for (uint32_t i = 1; i < n; ++i)
        ((n - i) % 2 == 0 ? even : odd).push_back(i);

    for (auto v: odd)
        cout << v << " ";
    std::reverse(odd.begin(), odd.end());
    for (auto v: odd)
        cout << v << " ";

    for (auto v: even)
        cout << v << " ";
    cout << n << " ";
    std::reverse(even.begin(), even.end());
    for (auto v: even)
        cout << v << " ";
    cout << n << " ";
    
    cout << "\n";
    
    return 0;
}