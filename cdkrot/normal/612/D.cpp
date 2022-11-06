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

struct event {
    int32_t pos;
    char type; // 0 - open, 1 - close.

    bool operator<(const event& other) const {
        return pos < other.pos or (pos == other.pos and type < other.type);
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n = input<uint32_t>();
    uint32_t k = input<uint32_t>();

    vector<event> events;
    for (uint32_t i = 0; i != n; ++i) {
        int32_t l, r;
        cin >> l >> r;
        events.push_back(event {l, 0});
        events.push_back(event {r, 1});
    }

    std::sort(events.begin(), events.end());
    uint32_t cnt = 0;

    vector<int32_t> pos;
    
    for (event& e: events) {
        if (e.type == 0)
            ++cnt;
        else
            --cnt;
            
        if (e.type == 0 and cnt == k)
            pos.push_back(e.pos);
        if (e.type == 1 and cnt == k - 1)
            pos.push_back(e.pos);
    }

    assert(pos.size() % 2 == 0);
    cout << pos.size() / 2 << "\n";
    for (uint32_t i = 0; i != pos.size(); ++i)
        cout << pos[i] << " \n"[i % 2];
    
    return 0;
}