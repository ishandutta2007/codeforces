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

int m, k, x;

const int mod = 1000 * 1000 * 1000 + 7;
int add(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int mult(int a, int b) {
    return int64_t(a) * b % mod;
}

vector<vector<int>> graph;

vector<vector<int>> comb(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> res(3, vector<int>(x + 1, 0));
    
    for (int us = 0; us <= x; ++us)
        for (int th = 0; th + us <= x; ++th) {
            res[0][us + th] = add(res[0][us + th], mult(a[0][us], add(b[0][th], add(b[1][th], b[2][th]))));
            res[1][us + th] = add(res[1][us + th], mult(a[1][us], b[0][th]));
            res[2][us + th] = add(res[2][us + th], mult(a[2][us], add(b[0][th], b[2][th])));
        }

    return res;
}

vector<vector<int>> dfs(int v, int p) {
    vector<vector<int>> res(3, vector<int>(x + 1, 0));
    res[0][0] = k - 1;
    res[1][1] = 1;
    res[2][0] = m - k;
    
    for (int u: graph[v])
        if (u != p) {
            auto sub = dfs(u, v);

            res = comb(res, sub);
        }
    return res;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    m = input<int>();

    graph.resize(n);
    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;
        graph[v].pb(u);
        graph[u].pb(v);
    }

    k = input<int>();
    x = input<int>();

    vector<vector<int>> ans = dfs(0, -1);
    int zzz = 0;
    for (int i = 0; i != 3; ++i)
        for (int j = 0; j <= x; ++j)
            zzz = add(zzz, ans[i][j]);
    cout << zzz << "\n";
    
    return 0;
}