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

    uint32_t n, k, a, b, c, d;
    cin >> n >> k >> a >> b >> c >> d;

    if (k <= n or n == 4)
        cout << "-1\n";
    else {
        vector<uint32_t> list;
        for (uint32_t i = 1; i <= n; ++i)
            if (i != a and i != b and i != c and i != d)
                list.push_back(i);
        assert(list.size() == n - 4);

        cout << a << " " << c << " ";
        for (auto v: list)
            cout << v << " ";
        cout << d << " " << b << "\n";

        cout << c << " " << a << " ";
        for (auto v: list)
            cout << v << " ";
        cout << b << " " << d << "\n";
    }
    
    return 0;
}