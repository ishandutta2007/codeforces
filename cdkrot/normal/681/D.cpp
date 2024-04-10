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

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

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

#define time TIME_FUCKLIBC

vector<vector<size_t>> graph;
vector<char> active;
vector<size_t> list;
size_t time;
vector<pair<size_t, size_t>> times;

void dfs(size_t v) {
    times[v].first = time++;
    for (size_t u: graph[v])
        dfs(u);

    times[v].second = time++;
    if (active[v])
        list.push_back(v);
}

bool INSIDE(pair<size_t, size_t> a, pair<size_t, size_t> b) {
    return a.first <= b.first and b.second <= a.second;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    size_t n, m;
    cin >> n >> m;
    
    graph.resize(n);
    active.resize(n, false);
    times.resize(n, make_pair(SIZE_MAX, SIZE_MAX));

    vector<char> has_parent(n, false);
    
    for (size_t i = 0; i != m; ++i) {
        auto v = input<size_t>() - 1;
        auto u = input<size_t>() - 1;
        graph[v].push_back(u);
        has_parent[u] = true;
    }

    vector<vector<size_t>> by_target(n);
    for (size_t i = 0; i != n; ++i) {
        size_t v = input<size_t>() - 1;
        by_target[v].push_back(i);
        active[v] = true;
    }

    for (size_t i = 0; i != n; ++i)
        if (not has_parent[i])
            dfs(i);
    
    std::set<pair<size_t, size_t>> cur;
    bool fail = false;
    for (size_t A: list) {
        for (size_t v: by_target[A]) {
            auto it = cur.upper_bound(times[v]);
            if (it != cur.begin() and not cur.empty() and INSIDE(*std::prev(it), times[v]))
                fail = true;
        }

        while (true) {
            auto it = cur.lower_bound(times[A]);
            if (it != cur.end() and INSIDE(times[A], *it))
                cur.erase(it);
            else
                break;
        }
        cur.insert(times[A]);
    }

    if (not fail) {
        cout << list.size() << "\n";
        for (auto v: list)
            cout << v + 1 << " ";
        cout << "\n";
    } else {
        cout << "-1\n";
    }
    return 0;
}