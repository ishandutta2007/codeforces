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

    uint32_t n, a, b;
    cin >> n >> a >> b;

    uint32_t num_wh = (a * b) / 2;
    uint32_t num_bl = (a * b) / 2 + (a * b) % 2;
    
    bool inv;
    if (n / 2 <= num_wh and n / 2 + n % 2 <= num_bl)
        inv = false;
    else if (n / 2 <= num_bl and n / 2 + n % 2 <= num_wh)
        inv = true;
    else {
        cout << "-1\n";
        return 0;
    }

    uint32_t st0 = 1, st1 = 2;
    if (inv)
        std::swap(st0, st1);
    
    for (uint32_t i = 0; i != a; ++i, cout <<"\n")
        for (uint32_t j = 0; j != b; ++j)
            if ((i + j) % 2 == 0) {
                // white.
                if (st0 <= n)
                    cout << st0 << " ", st0 += 2;
                else
                    cout << "0 ";
            } else {
                if (st1 <= n)
                    cout << st1 << " ", st1 += 2;
                else
                    cout << "0 ";
            }
    return 0;
}