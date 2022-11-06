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

vector<int> vdata;
vector<vector<int>> graph;
vector<int> eweight;

vector<int> euler;
vector<pair<int, int>> times;

void gen_euler(int v, int acc) {
    times[v].first = euler.size();
    euler.push_back(vdata[v] - acc);
    
    for (int u: graph[v])
        gen_euler(u, acc + eweight[u]);

    times[v].second = euler.size();
}


vector<int> segtree[2 * 262144];
void build_tree() {
    for (int i = 0; i != euler.size(); ++i)
        segtree[262143 + i] = {euler[i]};
    for (int i = 262142; i >= 0; --i) {
        segtree[i].resize(segtree[2 * i + 1].size() + segtree[2 * i + 2].size());
        std::merge(ALL(segtree[2 * i + 1]), ALL(segtree[2 * i + 2]), segtree[i].begin());
    }
}

template <typename FUNC>
void segtree_f(int node, int node_l, int node_r, int l, int r, FUNC handler) {
    if (l <= node_l and node_r <= r)
        handler(segtree[node]);
    else if (node_r <= l or r <= node_l) {}
    else {
        int mid = node_l + (node_r - node_l) / 2;
        segtree_f(2 * node + 1, node_l, mid, l, r, handler);
        segtree_f(2 * node + 2, mid, node_r, l, r, handler);
    }
}

#define INI(type) input<type>()

signed main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n = input<int>();
    vdata.resize(n);
    input_seq(ALL(vdata));

    eweight.resize(n, 0);
    graph.resize(n);
    
    for (int i = 1; i != n; ++i) {
        int p = INI(int) - 1;
        eweight[i] = INI(int);

        graph[p].push_back(i);
    }

    times.resize(n);
    gen_euler(0, 0);
    build_tree();

    
    for (int i = 0; i != n; ++i) {
        int ans = 0;
        if (times[i].first + 1 != times[i].second)
            segtree_f(0, 0, 262144, times[i].first + 1, times[i].second, [&ans, i](const vector<int>& part) {
                    ans += part.size() - (std::lower_bound(ALL(part), -vdata[i] + euler[times[i].first]) - part.begin());
                });
        cout << ans << " \n"[i == n - 1];
    }
    return 0;
}