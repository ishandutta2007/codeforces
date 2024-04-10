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

inline int other(const vector<int>& graph, int v) {
    LASSERT(SZ(graph) == 2 and (graph[0] == v or graph[1] == v));
    return graph[0] + graph[1] - v;
}

void dfs(const vector<vector<int>>& graph, vector<vector<pair<int, int>>>& compr, int v, int p) {
    for (int u: graph[v])
        if (u != p) {
            int t = u, len = 1, prev = v;
            
            while (SZ(graph[t]) == 2) {
                len += 1;
                int nw = other(graph[t], prev);
                
                prev = t;
                t = nw;
            }

            compr[v].emplace_back(t, len);
            compr[t].emplace_back(v, len);
            dfs(graph, compr, t, prev);
        }
}

int compress(vector<vector<pair<int, int>>>& compr, int v, int p) {
    vector<int> ch;
    for (pair<int, int>& u: compr[v])
        if (u.first != p) {
            int sub;
            if ((sub = compress(compr, u.first, v)) < 0)
                return sub;

            ch.push_back(sub + u.second);
        }

    if (ch.empty())
        return 0;
    
    std::sort(ch.begin(), ch.end());
    ch.resize(std::unique(ch.begin(), ch.end()) - ch.begin());

    if (ch.size() == 1)
        return ch[0];
    else if (p == -1 and ch.size() == 2)
        return ch[0] + ch[1];
    else
        return -1 - v;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<vector<int>> graph(n);
    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int root = 0;
    for (; root != n and graph[root].size() != 1; ++root) {}

    assert(root != n);

    vector<vector<pair<int, int>>> compressed(n);

    dfs(graph, compressed, root, -1);
    
    int ans = compress(compressed, root, -1);

    if (ans < 0) {
        ans = compress(compressed, -ans - 1, -1);
        if (ans < 0)
            ans = -1;
    }
    
    while (ans % 2 == 0)
        ans /= 2;

    cout << ans << "\n";
    
    return 0;
}