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
using std::tuple;

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
    int k = input<int>();

    vector<vector<int>> state(5, vector<int>(n + 1));
    for (int i = 1; i <= 4; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> state[i][j];

    vector<tuple<int, int, int>> ans;
    while (1) {
        for (int i = 1; i <= n; ++i)
            if (state[2][i] != 0 and state[1][i] == state[2][i]) {
                ans.emplace_back(state[2][i], 1, i);
                state[2][i] = 0;

                k -= 1;
            }

        for (int i = 1; i <= n; ++i)
            if (state[3][i] != 0 and state[3][i] == state[4][i]) {
                ans.emplace_back(state[3][i], 4, i);
                state[3][i] = 0;

                k -= 1;                
            }

        if (k == 0)
            break;

        if (k == 2 * n) {
            break; // deadlock;
        }

        vector<pair<int, int>> lst;
        for (int i = 1; i <= n; ++i)
            lst.emplace_back(2, i);
        for (int i = n; i >= 1; --i)
            lst.emplace_back(3, i);

        int pspace = 0;
        while (state[lst[pspace].first][lst[pspace].second] != 0)
            ++pspace;

        std::rotate(lst.begin(), lst.begin() + pspace, lst.end());
        for (int i = 1; i != SZ(lst); ++i) {
            if (state[lst[i].first][lst[i].second] != 0) {
                ans.emplace_back(state[lst[i].first][lst[i].second], lst[i - 1].first, lst[i - 1].second);

                std::swap(state[lst[i].first][lst[i].second], state[lst[i - 1].first][lst[i - 1].second]);
            }
        }
    }

    using std::get;
    if (k == 0) {
        cout << SZ(ans) << "\n";
        for (auto elem: ans)
            cout << get<0>(elem) << " " << get<1>(elem) << " " << get<2>(elem) << "\n";
    } else {
        cout << "-1\n";
    }
    
    return 0;
}