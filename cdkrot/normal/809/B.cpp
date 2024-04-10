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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    input<int>();

    auto bsearch_l = [](int l, int r) {
        assert(l <= r);
        while (l != r) {
            int m = l + (r - l + 1) / 2;
            cout << 1 << " " << m - 1 << " " << m << std::endl;
            
            if (input<string>() == "TAK")
                r = m - 1;
            else
                l = m;
        }
        return l;
    };

    auto bsearch_r = [n](int l, int r) {
        assert(l <= r);
        while (l != r) {
            int m = l + (r - l) / 2;
            cout << 1 << " " << m << " " << m + 1 << std::endl;
            
            if (input<string>() == "TAK")
                r = m;
            else
                l = m + 1;
        }
        return l;
    };
    
    int ans1 = bsearch_l(1, n);
    int ans2 = (ans1 == 1 ? -1 : bsearch_l(1, ans1 - 1));
    int ans3 = (ans1 == n ? -1 : bsearch_r(ans1 + 1, n));

    int fans = -1;
    if (ans2 != -1) {
        cout << 1 << " " << ans2 << " " << ans1 << std::endl;
        if (input<string>() == "TAK")
            fans = ans2;
    }
    
    if (fans == -1) {
        assert(ans3 != -1);
        fans = ans3;
        
//        cout << 1 << " " << ans3 << " " << ans1 << std::endl;
//        assert(input<string>() == "TAK");
    }

    cout << 2 << " " << ans1 << " " << fans << "\n";
    
    return 0;
}