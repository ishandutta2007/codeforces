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
#include <tuple>


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

#define pb push_back
#define eb emplace_back

const int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
    return (a + b) >= mod ? a + b - mod : a + b;
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

int fastpow(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2 == 1)
            r = mult(r, a);

        a = mult(a, a), n /= 2;
    }
    return r;
}

int count(int v) {
    if (v == 1)
        return 0;
    else
        return count(__builtin_popcount(v)) + 1;
}

bool LEQ(int a, const string& n) {
    if (n.size() > 15)
        return false;
    
    int nn = 0;
    for (int i = 0; i != SZ(n); ++i)
        nn = 2 * nn + n[i] - '0';
    return a <= nn;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    const int blad = 3000;
    vector<int> fact(blad);
    fact[0] = 1;

    for (int i = 1; i != blad; ++i)
        fact[i] = mult(i, fact[i - 1]);

    auto get_binom = [&](int n, int k) {
        if (k < 0 or k > n)
            return 0;

        return mult(fact[n], fastpow(mult(fact[k], fact[n - k]), mod - 2));
    };
    
    // code here.
    string n = input<string>();
    int k = input<int>();

    if (k == 0)
        cout << 1 << "\n";
    else {
        int ans = 0;
        vector<int> lst;
        
        for (int i = 1; i != 1024; ++i) {
            int t = count(i);
            if (t == k - 1)
                lst.push_back(i);
        }

        if (std::binary_search(ALL(lst), std::count(ALL(n), '1')))
            ans = add(ans, 1);
        
        int num_ones = 0;
        for (int p = 0; p != SZ(n); ++p)
            if (n[p] == '1') {
                int len = SZ(n) - 1 - p;

                for (int elem: lst) {
                    int target_ones = elem - num_ones;
                    if (target_ones >= 0)
                        ans = add(ans, get_binom(len, target_ones));
                }

                ++num_ones;
            }

        if (k == 1)
            ans = add(ans, mod - 1);
        
        cout << ans << "\n";
    }
    return 0;
}