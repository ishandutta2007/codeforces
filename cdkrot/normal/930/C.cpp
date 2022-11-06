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
    int n = input<int>();
    int m = input<int>();

    vector<int> psums(m + 1, 0);

    for (int i = 0; i != n; ++i) {
        int l, r;
        cin >> l >> r;

        --l, --r;

        psums[l] += 1;
        psums[r + 1] -= 1;
    }

    for (int i = 1; i != m + 1; ++i)
        psums[i] += psums[i - 1];

    vector<int> counts;
    for (int i = 0; i != m; ++i)
        counts.push_back(psums[i]);

    auto get_f = [](const vector<int>& arr) {
        vector<int> x;
        x.push_back(-1e9);

        vector<int> res(SZ(arr));
        for (int i = 0; i != SZ(arr); ++i) {
            auto it = std::upper_bound(ALL(x), arr[i]) - x.begin();
            res[i] = it;

            if (it == SZ(x))
                x.push_back(arr[i]);
            else
                x[it] = arr[i];
        }

        return res;
    };

    vector<int> lft = get_f(counts);
    
    std::reverse(ALL(counts));
    vector<int> rgh = get_f(counts);
    std::reverse(ALL(rgh));

    int ans = -1;

    for (int i = 0; i != m; ++i)
        ans = max(ans, lft[i] + rgh[i] - 1);

    cout << ans << "\n";
    
    
    return 0;
}