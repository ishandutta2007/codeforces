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

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

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

uint64_t mod = 1000 * 1000 * 1000 + 7;

uint64_t sum(uint64_t a, uint64_t b) {
    return (a + b) % mod;
}

uint64_t mult(uint64_t a, uint64_t b) {
    return (a * b) % mod;
}

uint64_t sub(uint64_t a, uint64_t b) {
    return sum(a, mod - (b % mod));
}

uint64_t fastpow(uint64_t a, uint64_t n) {
    uint64_t res = 1;
    while (n) {
        if (n % 2)
            res = mult(res, a);
        n /= 2;
        a = mult(a, a);
    }
    return res;
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint64_t a, b, n, x;
    cin >> a >> b >> n >> x;
    
    uint64_t f = mult(fastpow(a, n), x);
    uint64_t g;
    if (a == 1)
        g = mult(b, mult(n, 1));
    else
        g = mult(mult(b, sub(fastpow(a, n), 1)), fastpow(sub(a, 1), mod - 2));
    cout << sum(f, g) << "\n";
    
    return 0;
}