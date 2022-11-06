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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // event add, event destroy.
    auto req_cnt = input<uint32_t>();    
    auto max_q = input<uint32_t>() + 1;

    vector<pair<int64_t, int64_t>> reqs(req_cnt);
    for (uint32_t i = 0; i != req_cnt; ++i)
        cin >> reqs[i].first >> reqs[i].second;
        
    vector<int64_t> ans(req_cnt, INT64_MIN);

    std::queue<uint32_t> the_queue;
    int64_t next_queue_event = INT64_MAX;

    auto request_arrived = [&](uint32_t id) {
        if (the_queue.size() == max_q)
            ans[id] = -1;
        else {
            if (the_queue.empty())
                next_queue_event = reqs[id].first + reqs[id].second;
            the_queue.push(id);
        }
    };
    auto serve_request = [&]() {
        LASSERT(not the_queue.empty());
        ans[the_queue.front()] = next_queue_event;

        the_queue.pop();
        if (the_queue.empty())
            next_queue_event = INT64_MAX;
        else
            next_queue_event += reqs[the_queue.front()].second;
    };
    
    uint32_t cur_req = 0;
    while (cur_req != reqs.size() or next_queue_event != INT64_MAX) {
        if (cur_req == reqs.size())
            serve_request();
        else if (next_queue_event == INT32_MAX)
            request_arrived(cur_req++);
        else if (next_queue_event <= reqs[cur_req].first)
            serve_request();
        else
            request_arrived(cur_req++);
    }

    for (auto v: ans)
        cout << v << " ";
    cout << "\n";
    
    return 0;
}