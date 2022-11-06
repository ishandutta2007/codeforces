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

bool dfs(const vector<vector<int>>& graph, vector<char>& used, vector<int>& tout, int v) {
    used[v] = 1;
    for (int u: graph[v])
        if (used[u] == 1 or (used[u] == 0 and not dfs(graph, used, tout, u)))
            return false;
    used[v] = 2;
    tout.push_back(v);
    return true;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int k = input<int>();

    vector<int> key(k);
    for (int& v: key)
        v = input<int>() - 1;

    vector<vector<int>> graph(n);
    for (int i = 0; i != n; ++i) {
        graph[i].resize(input<int>());
        for (int& j: graph[i])
            j = input<int>() - 1;
    }

    vector<char> used(n, 0);
    vector<int> tout;
    for (int v: key)
        if (used[v] == 0 and not dfs(graph, used, tout, v)) {
            cout << "-1\n";
            return 0;
        }

    cout << tout.size() << "\n";
    for (int x: tout)
        cout << x + 1 << " ";
    cout << "\n";
    
    return 0;
}