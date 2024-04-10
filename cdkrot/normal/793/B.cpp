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

using std::tuple;
using std::get;

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

int dist[1001][1001][2];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n, m;
    n = input<int>();
    m = input<int>();

    int s1 = -1, s2 = -1;
    int t1 = -1, t2 = -1;
    
    vector<vector<char>> field(n, vector<char>(m));
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j) {
            field[i][j] = input<char>();

            if (field[i][j] == 'S') {
                field[i][j] = '.';
                s1 = i, s2 = j;
            }
            if (field[i][j] == 'T') {
                field[i][j] = '.';
                t1 = i, t2 = j;
            }
        }

    for (int i = 0; i != n; ++i)
        for (int j = 0; j != m; ++j)
            for (int t = 0; t != 2; ++t)
                dist[i][j][t] = TYPEMAX(int);

    for (int t = 0; t != 2; ++t)
        dist[s1][s2][t] = 0;

    std::queue<tuple<int, int, int>> q0, q1;
    for (int t = 0; t != 2; ++t)
        q0.emplace(s1, s2, t);
    
    while (not q0.empty() or not q1.empty()) {
        if (q0.empty())
            q0 = std::move(q1);
        
        int i, j, k;
        std::tie(i, j, k) = q0.front();
        q0.pop();

        auto relax0 = [&](int a, int b, int c) {
            if (field[a][b] == '*')
                return;
            
            if (dist[a][b][c] > dist[i][j][k]) {
                dist[a][b][c] = dist[i][j][k];
                q0.emplace(a, b, c);
            }
        };

        auto relax1 = [&](int a, int b, int c) {
            if (field[a][b] == '*')
                return;
            
            if (dist[a][b][c] > dist[i][j][k] + 1) {
                dist[a][b][c] = dist[i][j][k] + 1;
                q1.emplace(a, b, c);
            }
        };
        
        relax1(i, j, 1 - k);

        if (k % 2 == 0) {
            if (i != 0)
                relax0(i - 1, j, k);
            if (i + 1 != n)
                relax0(i + 1, j, k);
        } else {
            if (j != 0)
                relax0(i, j - 1, k);
            if (j + 1 != m)
                relax0(i, j + 1, k);
        }
    }

    cout << (min(dist[t1][t2][0], dist[t1][t2][1]) <= 2 ? "YES\n" : "NO\n");
    
    return 0;
}