// Copyright (C) 2018 Sayutin Dmitry.
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
#define int int64_t

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


int32_t main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    const int LOG = 60;

    vector<int> val_mod(LOG + 1), nod_mod(LOG + 1);

    for (int q = input<int>(); q != 0; --q) {
        int t = input<int>();

        auto get_dep = [](int val) {
            int ans = 0;
            while (val != 1)
                ans += 1, val /= 2;
            return ans;
        };
        
        if (t == 1) {
            int dep = get_dep(input<int>());
            int x = input<int>();

            x %= (int(1) << dep);
            if (x < 0)
                x += (int(1) << dep);

            val_mod[dep] += x;
            val_mod[dep] %= (int(1) << dep);
        }
        if (t == 2) {
            int dep = get_dep(input<int>());
            int x = input<int>();

            x %= (int(1) << dep);
            if (x < 0)
                x += (int(1) << dep);

            for (int i = dep; i <= LOG; ++i, x *= 2) {
                nod_mod[i] += x;
                nod_mod[i] %= (int(1) << i);
            }
        }

        if (t == 3) {
            auto shift = [&](int64_t x, bool tp) {
                int dep = get_dep(x);
                
                x -= (int(1) << dep);
                
                x += (not tp ? nod_mod[dep] : val_mod[dep]);
                x %= (int(1) << dep);
                
                x += (int(1) << dep);

                return x;
            };

            auto shift_back = [&](int64_t x, bool tp) {
                int dep = get_dep(x);
                
                x -= (int(1) << dep);
                
                x -= (not tp ? nod_mod[dep] : val_mod[dep]);
                x %= (int(1) << dep);
                if (x < 0)
                    x += (int(1) << dep);
                
                x += (int(1) << dep);

                return x;
            };

            
            int64_t x = input<int64_t>();

            x = shift(shift(x, false), true);
            
//            x = shift_back(x, true);
//            x = shift(x, false);
            
            cout << shift_back(shift_back(x, true), false) << " ";

            while (x != 1) {
                x /= 2;
                cout << shift_back(shift_back(x, false), true) << " ";
//                cout << shift_back(shift_back(x, false), true) << " ";
            }

            cout << "\n";
        }
    }
    
    return 0;
}