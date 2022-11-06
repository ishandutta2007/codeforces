// Copyright (C) 2017 Sayutin Dmitry.
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
#include <cstdint>
#include <cinttypes>
#include <string.h>
#include <random>
#include <numeric>


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

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define int int64_t

bool interV(int x, int y1, int y2, int px, int py, int vx, int vy, double& ans, bool strict=false) {
    if (vx != 0) {
        ans = (x - px) / double(vx);

        // y1 < py + vy (x - px) / vx <= y2
        // y1 vx^2 < py vx^2 + vy vx (x - px) <= y2 vx^2
        if (strict)
            return (y1 * vx * vx < py * vx * vx + vy * vx * (x - px) and py * vx * vx + vy * vx * (x - px) < y2 * vx * vx);
        else
            return (y1 * vx * vx <= py * vx * vx + vy * vx * (x - px) and py * vx * vx + vy * vx * (x - px) <= y2 * vx * vx);
    }

    // if we are not moving et all => captured by loop
    // if we are moving vertically & can be inside => other lines will handle
    // if we are moving vertically & can't be inside => nevermind
    return false;
}

bool interH(int y, int x1, int x2, int px, int py, int vx, int vy, double& ans) {
    return interV(y, x1, x2, py, px, vy, vx, ans, true);
}

signed main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    double mn = 0, mx = 1e100;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2 or y1 == y2)
        mn = 1e200;
    
    for (int i = 0; i != n; ++i) {
        int px, py, vx, vy;
        cin >> px >> py >> vx >> vy;

        if (vx == 0 and vy == 0) {
            if (x1 < px and px < x2 and y1 < py and py < y2)
                continue;
            else {
                mn = 1e200;
                continue;
            }
        }

        if (vx == 0 and (px == x1 or px == x2)) {
            mn = 1e200;
            continue;
        }

        if (vy == 0 and (py == y1 or py == y2)) {
            mn = 1e200;
            continue;
        }
        
        vector<double> pos;
        double temp;
        if (interV(x1, y1, y2, px, py, vx, vy, temp))
            pos.push_back(temp);
        if (interV(x2, y1, y2, px, py, vx, vy, temp))
            pos.push_back(temp);
        
        if (interH(y1, x1, x2, px, py, vx, vy, temp))
            pos.push_back(temp);
        if (interH(y2, x1, x2, px, py, vx, vy, temp))
            pos.push_back(temp);
        
        if (pos.size() <= 1)
            mn = 1e200;
        else {
            mn = max(mn, *std::min_element(ALL(pos)));
            mx = min(mx, *std::max_element(ALL(pos)));
        }
    }

    cout << std::fixed;
    cout.precision(10);
    
    if (mn <= mx - 1e-12)
        cout << mn << "\n";
    else
        cout << "-1\n";
    
    return 0;
}