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


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int64_t mx = TYPEMIN(int64_t);
    int n = input<int>();
    int64_t p = input<int64_t>();
    int64_t q = input<int64_t>();
    int64_t r = input<int64_t>();

    vector<int64_t> seq(n);
    input_seq(ALL(seq));

    auto comb = [](pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
        return make_pair(min(a.first, b.first), max(a.second, b.second));
    };
        
    vector<pair<int64_t, int64_t>> pref(n), suf(n);
    for (int i = 0; i != n; ++i) {
        pref[i] = {seq[i], seq[i]};
        if (i != 0)
            pref[i] = comb(pref[i - 1], pref[i]);
    }
    
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = {seq[i], seq[i]};
        if (i != n - 1)
            suf[i] = comb(suf[i], suf[i + 1]);
    }
    
    for (int i = 0; i != n; ++i)
        for (int64_t A: {pref[i].first, pref[i].second})
            for (int64_t B: {suf[i].first, suf[i].second})
                mx = max(mx, p * A + q * seq[i] + r * B);
    cout << mx << "\n";
    
    return 0;
}