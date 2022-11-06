// Copyright (C) 2016 "Time to emerge -e that world".
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

/*template <typename T>
struct window_max {
        uint32_t sz() {return in.size() + out.size();}
        uint32_t mx() {
            LASSERT(not in.empty() or not out.empty());
            if (in.empty())
                return out.top().second;
            if (out.empty())
                return in.top().second;
            return max(in.top().second, out.top().second);
        }
        void push(T val) {
            T the_max = val;
            if (not in.empty())
                the_max = max(the_max, in.top().second);
            in.emplace(val, the_max);
        }
        T pop() {
            LASSERT(not in.empty() or not out.empty());
            if (not out.empty()) {
                T res = out.top().first;
                out.pop();
                return res;
            }

            while (not in.empty()) {
                T v = 
            }
        }
        
        // (val, max)
        std::stack<pair<T, T>> in;
        std::stack<pair<T, T>> out;
        };*/

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int32_t n, m, s, d;
    cin >> n >> m >> s >> d;

    vector<int32_t> troubles(n + 1);
    std::generate(troubles.begin(), troubles.end() - 1, input<int32_t>);
    troubles.back() = m + 1;
    std::sort(troubles.begin(), troubles.end());

    vector<pair<int32_t, int32_t>> intervals;
    int32_t prev = 0;
    for (int32_t v: troubles) {
        if ((v == m + 1) or (v - 1 - prev >= s))
            intervals.emplace_back(prev, v - 1);
        prev = v + 1;
    }
    
#ifdef LOCAL
    for (auto v: intervals)
        cerr << v.first << " " << v.second << "\n";
#endif

    if (intervals.empty() or intervals.front().first != 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    
    bool scs = true;
    for (uint32_t i = 0; i + 1 < intervals.size(); ++i) {
        auto interv1 = intervals[i];
        auto interv2 = intervals[i + 1];
        if (not (interv2.first - interv1.second <= d))
            scs = false;
    }

    if (not scs)
        cout << "IMPOSSIBLE\n";
    else {
        uint32_t cur_interval = 0;

        while (cur_interval != intervals.size()) {
            if (cur_interval + 1 == intervals.size() and intervals[cur_interval].second == intervals[cur_interval].first) {}
            else
                cout << "RUN " << intervals[cur_interval].second - intervals[cur_interval].first << "\n";
            
            if (cur_interval + 1 != intervals.size())
                cout << "JUMP " << intervals[cur_interval + 1].first - intervals[cur_interval].second << "\n";
            cur_interval += 1;
        }
    }
    
    return 0;
}