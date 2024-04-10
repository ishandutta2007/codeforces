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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int m = input<int>();
    int k = input<int>();

    vector<vector<pair<int, int>>> graph(k + n + m);

    std::map<pair<int, int>, int> tr;
    for (int i = 0; i != k; ++i) {
        int a = input<int>() - 1;
        int b = input<int>() - 1;
        tr[make_pair(a, b)] = i;
    }

    const int dx[4] = {+1, -1, 0, 0};
    const int dy[4] = {0,   0, +1, -1};
    
    for (auto elem: tr) {
        int x = elem.first.first;
        int y = elem.first.second;

        for (int t = 0; t != 4; ++t)
            if (tr.find(make_pair(x + dx[t], y + dy[t])) != tr.end())
                graph[elem.second].emplace_back(tr.find(make_pair(x + dx[t], y + dy[t]))->second, 0);

        auto f = [n](int x) {
            vector<int> res = {x};
            if (x != 0)
                res.push_back(x - 1);
            if (x != n - 1)
                res.push_back(x + 1);
            return res;
        };

        auto g = [m](int y) {
            vector<int> res = {y};
            if (y != 0)
                res.push_back(y - 1);
            if (y != m - 1)
                res.push_back(y + 1);
            return res;
        };
        
        for (int xx: f(x)) {
            graph[elem.second].emplace_back(k + xx, 1);
            graph[k + xx].emplace_back(elem.second, 0);
        }

        for (int yy: g(y)) {
            graph[elem.second].emplace_back(k + n + yy, 1);
            graph[k + n + yy].emplace_back(elem.second, 0);
        }
    }

    vector<int> dist(k + n + m, TYPEMAX(int));
    std::deque<int> q;
    dist[tr.find(make_pair(0, 0))->second] = 0;
    q.push_back(tr.find(make_pair(0, 0))->second);

    while (not q.empty()) {
        int v = q.front();
        q.pop_front();

        for (auto e: graph[v])
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                
                if (e.second == 0)
                    q.push_front(e.first);
                else
                    q.push_back(e.first);
            }
    }

    int ans = TYPEMAX(int);
    auto it = tr.find(make_pair(n - 1, m - 1));
    if (it != tr.end())
        ans = dist[it->second];
    
    ans = min(ans, dist[k + n - 1]);
    ans = min(ans, dist[k + n + m - 1]);
    if (ans == TYPEMAX(int))
        ans = -1;
    cout << ans << "\n";
    return 0;
}