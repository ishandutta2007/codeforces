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

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define fori(i, n)      for (int i = 0; i != (n); ++i)
#define forir(i, n)     for (int i = (n) - 1; i >= 0; --i)
#define for64(i, n)     for (int64_t i = 0; i != (n); ++i)
#define for64r(i, n)    for (int64_t i = (n) - 1; i >= 0; --i)
#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define input_arr(b, e) std::generate((b), (e), input<decltype(*b)>)

void dfs(const vector<vector<int>>& graph, vector<char>& used, int v) {
    used[v] = true;
    for (int u: graph[v])
        if (not used[u])
            dfs(graph, used, u);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int r, c;
    cin >> r >> c;
    vector<vector<char>> field(r, vector<char>(c));
    for (int i = 0; i != r; ++i)
        for (int j = 0; j != c; ++j)
            cin >> field[i][j];

    vector<vector<int>> graph(r * c);
    for (int i = 0; i != r; ++i) {
        for (int j = 0; j != c; ++j) {
            if (field[i][j] == 'B') {
                if (i + 1 != r and field[i + 1][j] == 'B') {
                    graph[i * c + j].push_back((i + 1) * c + j);
                    graph[(i + 1) * c + j].push_back(i * c + j);
                }
                if (j + 1 != c and field[i][j + 1] == 'B') {
                    graph[i * c + j].push_back(i * c + j + 1);
                    graph[i * c + j + 1].push_back(i * c + j);
                }
            }
        }
    }

    int ans = 0;
    vector<char> used(r * c, false);
    for (int i = 0; i != r; ++i)
        for (int j = 0; j != c; ++j) {
            if (field[i][j] == 'B' and not used[i * c + j]) {
                ++ans;
                dfs(graph, used, i * c + j);
            }
        }

    cout << ans << "\n";
    return 0;
}