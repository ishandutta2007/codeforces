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

const int MOD = 1000 * 1000 * 1000 + 7;

struct num {
    num(): num(0) {}
    num(int val): val(val % MOD) {}
    
    num operator+(const num& other) {
        return num(val + other.val);
    }
    num operator-(const num& other) {
        return *this + num(MOD - other.val);
    }
    num operator*(const num& other) {
        int64_t prod = val * int64_t(other.val);
        prod %= MOD;
        return num(prod);
    }
    num operator/(const num& other);
    
    int val;
};

num fastpow(num a, int n) {
    num res(1);

    while (n) {
        if (n % 2 == 1)
            res = res * a;
        n /= 2, a = a * a;
    }
    return res;
}

num num::operator/(const num& other) {
    return *this * fastpow(other.val, MOD - 2);
}

const int CACHE = 200 * 10000 + 10;
num fact[CACHE];
num rev_fact[CACHE];

#define OPEN 1
#define CLOSE 0

num comb(int n, int k) {
    return fact[n] * rev_fact[k] * rev_fact[n - k];
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    rev_fact[0] = fact[0] = 1;
    
    for (int i = 1; i != CACHE; ++i) {
        fact[i] = fact[i - 1] * num(i);
        rev_fact[i] = num(1) / fact[i];
    }
        
    int k, n;
    cin >> n >> k;
    vector<pair<int, bool>> events;
    for (int i = 0; i != n; ++i) {
        int L, R;
        cin >> L >> R;
        events.emplace_back(L, OPEN);
        events.emplace_back(R + 1, CLOSE);
    }
        
    
    std::sort(events.begin(), events.end());
    num ans(0);
    int cur_open = 0;
    for (int i = 0; i != events.size(); ++i) {
        if (i != 0 and cur_open >= k) {
            int delta = events[i].first - events[i - 1].first;
            ans = ans + num(delta) * comb(cur_open, k);
        }
        
        if (events[i].second == OPEN)
            ++cur_open;
        else
            --cur_open;

    }
    cout << ans.val << "\n";
    return 0;
}