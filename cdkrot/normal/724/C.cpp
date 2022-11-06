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
#include <cstdint>
#include <cinttypes>

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

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

#define int int64_t

// (to, descriptor).
vector<vector<pair<int, int>>> graph;

std::map<int, vector<int>> idsbydescr;

signed main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n, m, k;
    cin >> n >> m >> k;

    auto GET = [n, m](int id) {
        if (id < n)
            return make_pair(id, (int)0);
        if (id < n + m)
            return make_pair(n, id - n);
        if (id < n + m + n)
            return make_pair(2 * n + m - id, m);
        return make_pair((int)0, 2 * n + 2 * m - id);
    };

    auto GET_DIST = [](pair<int, int> p1, pair<int, int> p2) {
        return (abs(p1.first - p2.first) + abs(p1.second - p2.second)) / 2;
    };

    graph.resize(2 * n + 2 * m);

    {
        int i = 1;
        int j = graph.size() - 1;
        int desc = 1;
        while (i != j) {
            graph[i].emplace_back(j, desc);
            graph[j].emplace_back(i, desc);
            ++i, --j, desc++;
        }
    }
    
    {
        int i = 2 * n + m + 1;
        int j = 2 * n + m - 1;
        int desc = 50 * 100500 + 1;
        while (i != j) {
            graph[i].emplace_back(j, desc);
            graph[j].emplace_back(i, desc);
            
            i = (i + 1) % (2 * n + 2 * m);
            j = (j + 2 * n + 2 * m - 1) % (2 * n + 2 * m);
            desc++;
        }
    }

    vector<int> ans(k, TYPEMAX(int));
    vector<pair<int, int>> ansin(k);
    for (int i = 0; i != k; ++i) {
        int x, y;
        cin >> x >> y;
        idsbydescr[x + y].push_back(i);
        idsbydescr[x - y + m +  50 * 100500].push_back(i);
        ansin[i] = {x, y};
    }

    vector<char> visited(2 * n + 2 * m, 0);
    int v = 0;
    int prev = -1;
    int time = 0;
    while (visited[v] < 3) {
        visited[v] += 1;

        pair<int, int> next;
        if (graph[v].size() == 1) {
            if (prev == -1)
                next = graph[v][0];
            else
                break; // end.
        } else {
            assert(graph[v].size() == 2);
            assert(graph[v][0].first == prev or graph[v][1].first == prev);
            if (graph[v][0].first == prev)
                next = graph[v][1];
            else
                next = graph[v][0];
        }

        prev = v;
        v = next.first;
        for (int pans: idsbydescr[next.second]) {
            if (ans[pans] == TYPEMAX(int))
                ans[pans] = time + GET_DIST(GET(prev), ansin[pans]);
        }
        time += GET_DIST(GET(prev), GET(v));
    }

    for (int i = 0; i != ans.size(); ++i)
        if (ans[i] == TYPEMAX(int))
            cout << "-1\n";
        else
            cout << ans[i] << "\n";
    return 0;
}