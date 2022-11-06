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
#include <cstdint>
#include <cinttypes>

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

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int64_t psqrt(int64_t a) {
    int64_t b = max(int64_t(0), int64_t(std::sqrt(a * 1.0L) - 20));
    for (int64_t c = b; c != b + 40; ++c)
        if (c * c == a)
            return c;
    
    return TYPEMIN(int64_t);
}

void die() {
    cout << "Impossible\n";
    exit(0);
}

void try_solve(int64_t n0, int64_t n1, int64_t n01, int64_t n10) {
    if (n01 + n10 != n0 * n1)
        return;
    if (n0 + n1 == 0)
        return;
    
    // success!.
    vector<int64_t> p1;
    for (int i = 0; i != n1; ++i) {
        int64_t delta = min(n0, n01);
        n01 -= delta;
        p1.push_back(delta);
    }
    assert(n01 == 0);

    string ans = "";
    
    std::sort(ALL(p1));
    int ptr = 0;
    while (ptr != SZ(p1) and p1[ptr] == 0) {
        ans += '1';
        ++ptr;
    }

    for (int i = 0; i != n0; ++i) {
        ans += '0';
        while (ptr != SZ(p1) and p1[ptr] == i + 1) {
            ans += '1';
            ++ptr;
        }
    }
    cout << ans << "\n";
    exit(0);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;

    if (psqrt(8 * a + 1) == TYPEMIN(int64_t))
        die();
    if (psqrt(8 * d + 1) == TYPEMIN(int64_t))
        die();

    auto d0 = psqrt(8 * a + 1), d1 = psqrt(8 * d + 1);

    if ((1 + d0) % 2 == 0 and 1 + d0 >= 0) {
        if ((1 + d1) % 2 == 0 and 1 + d1 >= 0)
            try_solve((1 + d0) / 2, (1 + d1) / 2, b, c);
        if ((1 + d1) % 2 == 0 and 1 - d1 >= 0)
            try_solve((1 + d0) / 2, (1 - d1) / 2, b, c);
    }
    if ((1 - d0) % 2 == 0 and 1 - d0 >= 0) {
        if ((1 + d1) % 2 == 0 and 1 + d1 >= 0)
            try_solve((1 - d0) / 2, (1 + d1) / 2, b, c);
        if ((1 + d1) % 2 == 0 and 1 - d1 >= 0)
            try_solve((1 - d0) / 2, (1 - d1) / 2, b, c);
    }

    die();
    
    return 0;
}