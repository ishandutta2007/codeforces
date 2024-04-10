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

#define int int64_t

signed main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int s = input<int>();

    int64_t base = 0ll;
    vector<pair<int, int>> p1, p2;

    int64_t num1 = 0ll, num2 = 0ll;
    
    for (int i = 0ll; i != n; ++i) {
        int s = input<int>();
        int a = input<int>();
        int b = input<int>();

        base += max(a, b) * int64_t(s);
        if (a >= b)
            p1.emplace_back(a - b, s), num1 += s;
        else
            p2.emplace_back(b - a, s), num2 += s;
    }

    std::sort(ALL(p1));
    std::sort(ALL(p2));
    
    int64_t pz = (num1 + num2 + s - 1) / s;
    int64_t best = TYPEMIN(int64_t);
    for (int64_t fst = max(int64_t(0), num1 / s - 5); fst <= min(pz, num1 / s + 5); ++fst) {
        int64_t sn = s * (pz - fst);
        int64_t fs = s * fst;

        fs = max(int64_t(0), num1 - fs);
        sn = max(int64_t(0), num2 - sn);
        
        int64_t penal = 0ll;
        for (auto elem: p1) {
            int64_t cnt = min(elem.second, fs);
            fs -= cnt;
            penal += cnt * elem.first;
        }

        for (auto elem: p2) {
            int64_t cnt = min(elem.second, sn);
            sn -= cnt;
            penal += cnt * elem.first;
        }

//        cerr << penal << std::endl;
        best = max(best, base - penal);
    }

    cout << best << "\n";
    
    return 0;
}