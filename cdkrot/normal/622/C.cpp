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
#include <functional>
#include <utility>
#include <string>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::set;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::abs;
using std::max;

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

struct query {
    uint32_t l;
    uint32_t r;
    uint32_t x;
    uint32_t ans;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<uint32_t> arr(input<uint32_t>());
    vector<query>    queries(input<uint32_t>());
    vector<uint32_t> order(queries.size());
    
    std::generate(arr.begin(), arr.end(), input<uint32_t>);
    for (uint32_t i = 0; i != queries.size(); ++i) {
        auto& q = queries[i];
        
        cin >> q.l >> q.r >> q.x;
        --q.l, --q.r, q.ans = UINT32_MAX;

        order[i] = i;
    }

    std::sort(order.begin(), order.end(), [&queries](uint32_t a, uint32_t b) {
            return queries[a].l < queries[b].l;
        });
    
    // q.x -> query ids.
    std::map<uint32_t, vector<uint32_t>> cur_queries;
    uint32_t ptr = 0;
    for (uint32_t i = 0; i != arr.size(); ++i) {
        while (ptr != order.size() and queries[order[ptr]].l == i)
            cur_queries[queries[order[ptr]].x].push_back(order[ptr]), ++ptr;

        for (auto& dat: cur_queries)
            if (dat.first != arr[i]) {
                for (uint32_t v: dat.second)
                    if (queries[v].r >= i)
                        queries[v].ans = i;
                dat.second.clear(), dat.second.shrink_to_fit();
            }
        
        auto it = cur_queries.find(arr[i]);
        cur_queries.erase(cur_queries.begin(), it);
        if (it != cur_queries.end())
            ++it;
        cur_queries.erase(it, cur_queries.end());
    }

    for (auto q: queries) {
        if (q.ans == UINT32_MAX)
            cout << "-1\n";
        else
            cout << q.ans + 1 << "\n";
    }
    return 0;
}