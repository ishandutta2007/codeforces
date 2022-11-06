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

#include <unordered_map>

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int cur_id = 0;
    std::unordered_map<string, int> ids(int(1e6));
    vector<int> counts;
    counts.reserve(int(1e6));
    
    vector<string> lst(input<int>());
    input_seq(ALL(lst));

    for (int i = 0; i != SZ(lst); ++i) {
        vector<int> xid;
        for (int j = 0; j != 9; ++j)
            for (int k = j; k != 9; ++k) {
                string s = lst[i].substr(j, k - j + 1);
                if (not ids.count(s))
                    ids[s] = cur_id++, counts.push_back(0);

                xid.push_back(ids[s]);
            }

        std::sort(ALL(xid));
        xid.resize(std::unique(ALL(xid)) - xid.begin());

        for (int id: xid)
            counts[id] += 1;
    }

    for (int i = 0; i != SZ(lst); ++i) {
        for (int len = 1; len <= 9; ++len)
            for (int start = 0; start + len <= 9; ++start) {
                int s = ids[lst[i].substr(start, len)];

                if (counts[s] == 1) {
                    cout << lst[i].substr(start, len) << "\n";
                    goto end;
                }
            }
        assert(false);
    end:;
    }
    
    return 0;
}