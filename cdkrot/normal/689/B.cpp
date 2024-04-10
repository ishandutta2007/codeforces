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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = input<int>();
    vector<vector<int>> graph(n);
    for (int i = 0; i != n; ++i) {
        graph[i].push_back(input<int>() - 1);
        if (i != 0) {
            graph[i].push_back(i - 1);
            graph[i - 1].push_back(i);
        }
    }

    vector<int> dist(n, std::numeric_limits<int>::max());
    dist[0] = 0;
    std::queue<int> qu;
    qu.push(0);
    
    while (not qu.empty()) {
        int v = qu.front();
        qu.pop();
        for (int u: graph[v])
            if (dist[u] == std::numeric_limits<int>::max()) {
                dist[u] = dist[v] + 1;
                qu.push(u);
            }
    }

    for (int i = 0; i != n; ++i)
        cout << dist[i] << " \n"[i + 1 == n];
    
    return 0;
}