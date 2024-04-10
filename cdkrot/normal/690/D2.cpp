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
using std::reverse;
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

#define fori(i, n)      for (int i = 0; i != (n); ++i)
#define forir(i, n)     for (int i = (n) - 1; i >= 0; --i)
#define for64(i, n)     for (int64_t i = 0; i != (n); ++i)
#define for64r(i, n)    for (int64_t i = (n) - 1; i >= 0; --i)
#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define input_arr(b, e) std::generate((b), (e), input<decltype(*b)>)

const int64_t mod = 1000 * 1000 + 3;

int64_t fastpow(int64_t a, int32_t n) {
    int64_t res = 1;
    while (n) {
        if (n % 2 == 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }
    return res;
}

const int32_t prec_max = 710 * 1000;
int64_t fact[prec_max];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
    for (int64_t i = 2; i * i <= mod; ++i)
        assert(mod % i != 0);
    */
    
    for (int64_t i = 0; i != prec_max; ++i) 
        if (i == 0)
            fact[i] = 1;
        else
            fact[i] = (i * fact[i - 1]) % mod;
    
    int64_t ans = 0;
    int64_t n, c;
    cin >> n >> c;
    for (int64_t i = 1; i <= n; ++i) {
        int64_t dans = fact[i + c - 1] * fastpow(fact[i], mod - 2);
        dans %= mod;

        ans += dans;
        if (ans >= mod)
            ans -= mod;
    }
    ans *= fastpow(fact[c - 1], mod - 2);
    ans %= mod;
    cout << ans << "\n";
    
    return 0;
}