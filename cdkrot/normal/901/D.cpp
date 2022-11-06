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
#include <tuple>


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

#define pb push_back
#define eb emplace_back

struct edge {
    int to;
    int id;
};

vector<int> dfs(const vector<vector<edge>>& graph, vector<char>& color, int v) {
    for (edge e: graph[v]) {
        int u = e.to;
        
        if (color[u] == -1) {
            color[u] = 1 - color[v];

            vector<int> resp = dfs(graph, color, u);
            if (not resp.empty()) {
                if (resp.size() == 1 or resp[0] != resp.back())
                    resp.push_back(v);
                return resp;
            }
        } else if (color[u] == color[v]) {
            // whoops.
            vector<int> fly = {u, v};
            return fly;
        }
    }
    return vector<int> {};
}

int64_t solve_tree(vector<vector<edge>>& graph, vector<int>& wgh, vector<char>& used, vector<int64_t>& ans, int v) {
    used[v] = 1;
    int64_t total = 0;
    
    for (edge e: graph[v])
        if (not used[e.to]) {
            int64_t resp = solve_tree(graph, wgh, used, ans, e.to);
            ans[e.id] = wgh[e.to] - resp;

            total += wgh[e.to] - resp;
        }

    return total;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n, m;
    cin >> n >> m;

    vector<int> wgh(n);
    input_seq(ALL(wgh));

    vector<vector<edge>> graph(n);
    std::map<pair<int, int>, int> keker;
    for (int i = 0; i != m; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(edge {u, i});
        graph[u].push_back(edge {v, i});

        keker[make_pair(v, u)] = i;
        keker[make_pair(u, v)] = i;
    }

    vector<char> color(n, -1);
    color[0] = 0;
    
    vector<int> resp = dfs(graph, color, 0);

    vector<int64_t> ans(m, 0);
    
    if (resp.empty()) {
        // graph is bipartite.

        int s[2] = {0, 0};
        for (int v = 0; v != n; ++v)
            s[int(color[v])] += wgh[v];

        if (s[0] != s[1]) {
            cout << "NO\n";
            return 0;
        }

        vector<char> used(n, false);
        assert(solve_tree(graph, wgh, used, ans, 0) == wgh[0]);
    } else {
        vector<char> used(n, false);
        int64_t tot = wgh[resp[0]] - solve_tree(graph, wgh, used, ans, resp[0]);
        assert(tot % 2 == 0);

        for (int i = 0; i + 1 != SZ(resp); ++i)
            ans[keker[make_pair(resp[i], resp[i + 1])]] += (tot / 2) * (i % 2 == 0 ? +1 : -1);
    }

    cout << "YES\n";
    for (int i = 0; i != m; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}