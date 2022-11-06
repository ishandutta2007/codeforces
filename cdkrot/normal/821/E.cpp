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

const int mod = 1000000007;
int add(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int sub(int a, int b) {
    return a >= b ? a - b : mod + a - b;
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

struct m16 {
    m16(): m16(0) {}

    m16(int t) {
        for (int i = 0; i != 16; ++i)
            for (int j = 0; j != 16; ++j)
                m[i][j] = (i == j ? t : 0);
    }

    
    int* operator[](int a) {
        return m[a];
    }

    const int* operator[](int a) const {
        return m[a];
    }
    
    int m[16][16];
};

struct v16 {
    v16() {
        for (int i = 0; i != 16; ++i)
            v[i] = 0;
    }

    int& operator[](int a) {
        return v[a];
    }

    const int& operator[](int a) const {
        return v[a];
    }

    int v[16];
};

m16 mult(const m16& a, const m16& b) {
    m16 res;
    
    for (int i = 0; i != 16; ++i)
        for (int j = 0; j != 16; ++j)
            for (int k = 0; k != 16; ++k)
                res[i][k] = add(res[i][k], mult(a[i][j], b[j][k]));
    return res;
}

v16 mult(const m16& a, const v16& b) {
    v16 res;
    
    for (int i = 0; i != 16; ++i)
        for (int j = 0; j != 16; ++j)
            res[i] = add(res[i], mult(a[i][j], b[j]));
    return res;
}

m16 fastpow(m16 a, int64_t n) {
    m16 r(1);
    while (n != 0) {
        if (n % 2)
            r = mult(r, a);
        n /= 2;
        a = mult(a, a);
    }
    return r;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int64_t k = input<int64_t>();

    v16 ans;
    ans[0] = 1;

    for (int i = 0; i != n; ++i) {
        int64_t a = input<int64_t>();
        int64_t b = input<int64_t>();

        if (b > k)
            b = k;
        
        int c = input<int>();

        // for (int i = c + 1; i != 16; ++i)
        //     ans[i] = 0;

        m16 tr;
        for (int i = 0; i <= c; ++i) {
            tr[i][i] = 1;

            if (i != 0)
                tr[i][i - 1] = 1;
            if (i != c)
                tr[i][i + 1] = 1;
        }
        
        ans = mult(fastpow(tr, b - a), ans);
    }

    cout << ans[0] << "\n";
    
    return 0;
}