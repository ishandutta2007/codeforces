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

bool dfs(const vector<vector<pair<int, bool>>>& graph, vector<char>& res, int v, int des) {
    if (res[v] == -1)
        res[v] = des;
    else
        return res[v] == des;

    for (auto go: graph[v])
        if (not dfs(graph, res, go.first, des ^ go.second))
            return false;
    return true;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int m = input<int>();

    vector<char> state(n);
    for (int i = 0; i != n; ++i)
        state[i] = 1 - input<int>();

    vector<vector<int>> refs(n);

    for (int i = 0; i != m; ++i)
        for (int t = input<int>(); t != 0; --t)
            refs[input<int>() - 1].push_back(i);

    vector<vector<pair<int, bool>>> graph(m);
    for (int i = 0; i != n; ++i) {
        int a = refs[i][0];
        int b = refs[i][1];

        graph[a].emplace_back(b, state[i]);
        graph[b].emplace_back(a, state[i]);
    }
    
    vector<char> res(m, -1);
    bool ok = true;
    for (int i = 0; i != m and ok; ++i)
        if (res[i] == -1)
            ok = dfs(graph, res, i, 0);

    cout << (ok ? "YES\n" : "NO\n");
    
    return 0;
}