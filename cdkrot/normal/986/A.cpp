// Copyright (C) 2018 Sayutin Dmitry.
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

const int max_n = 1.1e5;
const int max_k = 105;

int dist[max_n][max_k];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<vector<int>> by_type(k);
    for (int i = 0; i != n; ++i)
        by_type[input<int>() - 1].push_back(i);
    
    vector<vector<int>> graph(n);
    for (int i = 0; i != m; ++i) {
        int v, u;

        cin >> v >> u;
        --v, --u;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    int inf = 1e9;
    for (int tp = 0; tp != k; ++tp) {
        for (int i = 0; i != n; ++i)
            dist[i][tp] = inf;

        std::queue<int> go; // (v).
        for (int v: by_type[tp]) {
            dist[v][tp] = 0;
            go.emplace(v);
        }

        while (not go.empty()) {
            int v = go.front();
            go.pop();

            for (int u: graph[v])
                if (dist[u][tp] > dist[v][tp] + 1) {
                    dist[u][tp] = dist[v][tp] + 1;
                    go.push(u);
                }
        }
    }

    for (int i = 0; i != n; ++i) {
        std::sort(dist[i], dist[i] + k);
        int ans = 0;
        for (int j = 0; j != s; ++j)
            ans += dist[i][j];

        cout << ans << "\n";
    }
    
    return 0;
}