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

const int maxn = 3e5;

int64_t count[maxn][10];
int64_t sum[maxn][10];

vector<vector<int>> graph;
int k;

int64_t dfs(int v, int p) {
    int64_t ans = 0;
    
    for (int u: graph[v]) {
        if (u == p)
            continue;
        
        ans += dfs(u, v);

        for (int i = 0; i != k; ++i) {
            count[v][(i + 1) % k] += count[u][i];
            sum[v][(i + 1) % k]   += sum[u][i] + count[u][i];
        }

        for (int i = 0; i != k; ++i)
            for (int j = i + 1; j != k; ++j) {
                ans -= (count[u][i] * sum[u][j] + count[u][j] * sum[u][i] + (2 + (k - (i + j + 2) % k) % k) * count[u][i] * count[u][j]) / k;
                assert((count[u][i] * sum[u][j] + count[u][j] * sum[u][i] + (2 + (k - (i + j + 2) % k) % k) * count[u][i] * count[u][j]) % k == 0);
            }
        
        for (int i = 0; i != k; ++i) {
            ans -= ((count[u][i] - 1) * sum[u][i] + (2 + (k - (i * 2 + 2) % k) % k) * count[u][i] * (count[u][i] - 1) / 2) / k;
            assert( ((count[u][i] - 1) * sum[u][i] + (2 + (k - (i * 2 + 2) % k) % k) * count[u][i] * (count[u][i] - 1) / 2) % k == 0);
        }
    }

    count[v][0] += 1;
    
    for (int i = 0; i != k; ++i)
        for (int j = i + 1; j != k; ++j) {
            ans += (count[v][i] * sum[v][j] + count[v][j] * sum[v][i] + ((k - (i + j) % k) % k) * count[v][i] * count[v][j]) / k;
            assert( (count[v][i] * sum[v][j] + count[v][j] * sum[v][i] + ((k - (i + j) % k) % k) * count[v][i] * count[v][j]) % k == 0 );
        }
    
    for (int i = 0; i != k; ++i) {
        ans += ((count[v][i] - 1) * sum[v][i] + ((k - (i * 2) % k) % k) * count[v][i] * (count[v][i] - 1) / 2) / k;
        assert( ((count[v][i] - 1) * sum[v][i] + ((k - (i * 2) % k) % k) * count[v][i] * (count[v][i] - 1) / 2) % k == 0);
    }

    return ans;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    graph.resize(input<int>());
    k = input<int>();

    for (int i = 1; i != SZ(graph); ++i) {
        int a = input<int>() - 1;
        int b = input<int>() - 1;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << dfs(0, -1) << "\n";
    
    return 0;
}