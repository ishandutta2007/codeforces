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

// must fix entire subtree
void fix(const vector<vector<int>>& graph, vector<int>& color, vector<int>& ans, int v, int p) {
    if (p != -1) {
        ans.push_back(v);
        color[v] = -color[v];
    }
    
    for (int u: graph[v])
        if (u != p) {
            fix(graph, color, ans, u, v);
            ans.push_back(v);
            color[v] = -color[v];
        }

    if (color[v] == -1) {
        if (p != -1) {
            ans.push_back(p);
            ans.push_back(v);

            color[p] = -color[p];
            color[v] = -color[v];
        } else {
            // p == -1, then fix by son.
            ans.push_back(graph[v][0]);
            ans.push_back(v);
            ans.push_back(graph[v][0]);
            color[v] = -color[v];
        }
    }
}


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<vector<int>> graph(n);

    vector<int> color(n);
    input_seq(ALL(color));

    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    if (std::count(ALL(color), -1) == 0)
        cout << "1\n";
    else {
        vector<int> ans = {0};
        fix(graph, color, ans, 0, -1);

        for (auto v: ans)
            cout << v + 1 << " ";
        cout << "\n";
    }
    
    return 0;
}