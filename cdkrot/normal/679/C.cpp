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

void dfs(const vector<vector<int>>& graph, int v, vector<int>& compid, vector<int>& compcnt) {
    for (int u: graph[v])
        if (compid[u] == -1) {
            compid[u] = compid[v];
            compcnt[compid[v]] += 1;
            dfs(graph, u, compid, compcnt);
        }
}

int main() {
    int n, k;
    scanf("%d %d\n", &n, &k);
    vector<vector<char>> field(n, vector<char>(n + 2));
    
    for (int i = 0; i != n; ++i) {
        fgets(field[i].data(), n + 2, stdin);
        field[i].resize(n);
    }

    vector<vector<int>> graph(n * n);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j) {
            if (field[i][j] == '.' and i != 0 and field[i - 1][j] == '.') {
                graph[n * i + j].push_back(n * (i - 1) + j);
                graph[n * (i - 1) + j].push_back(n * i + j);
            }
            if (field[i][j] == '.' and j != 0 and field[i][j - 1] == '.') {
                graph[n * i + j].push_back(n * i + j - 1);
                graph[n * i + (j - 1)].push_back(n * i + j);
            }
        }

    vector<int> compid(n * n, -1);
    vector<int> compcnt;
    int id = 0;
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            if (field[i][j] == '.' and compid[i * n + j] == -1) {
                compid[i * n + j] = id++;
                compcnt.push_back(1);
                dfs(graph, i * n + j, compid, compcnt);
            }

    int bestans = 0;
    int stamp = 0;
    vector<int> compmark(id, -1);
    for (int i0 = 0; i0 + k != n + 1; ++i0) {
        vector<int> compans = compcnt;
        for (int j0 = 0; j0 <= n; ++j0) {
            int ansthis = min(k, j0) * k;
            ++stamp;
            
            auto selectcomp = [&](int comp) {
                if (compmark[comp] != stamp)
                    compmark[comp] = stamp, ansthis += compans[comp];
            };
            for (int kid = 0; kid != k; ++kid) {
                if (i0 != 0 and j0 >= k and field[i0 - 1][j0 - k + kid] == '.')
                    selectcomp(compid[n * (i0 - 1) + (j0 - k + kid)]);
                if (i0 + k < n and j0 >= k and field[i0 + k][j0 - k + kid] == '.')
                    selectcomp(compid[n * (i0 + k) + (j0 - k + kid)]);
                if (j0 != n and field[i0 + kid][j0] == '.')
                    selectcomp(compid[n * (i0 + kid) + j0]);
                if (j0 >= k + 1 and field[i0 + kid][j0 - k - 1] == '.')
                    selectcomp(compid[n * (i0 + kid) + j0 - k - 1]);
            }
            
            bestans = max(bestans, ansthis);
            if (j0 != n)
                for (int kid = 0; kid != k; ++kid) {
                    if (field[i0 + kid][j0] == '.')
                        compans[compid[n * (i0 + kid) + j0]] -= 1;
                    if (j0 >= k and field[i0 + kid][j0 - k] == '.')
                        compans[compid[n * (i0 + kid) + j0 - k]] += 1;
                }
        }
    }

    cout << bestans << "\n";
    
    return 0;
}