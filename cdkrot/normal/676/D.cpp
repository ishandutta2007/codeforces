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

const int32_t maxn = 1000;

int get_id(int dim, int i, int j) {
    return dim * (maxn * maxn) + (i * maxn) + j;
}
int get_dim(int id) {
    return id / (maxn * maxn);
}
int get_i(int id) {
    return (id % (maxn * maxn)) / maxn;
}
int get_j(int id) {
    return id % maxn;
}

const char MASK_UP    = 1;
const char MASK_RIGHT = 2;
const char MASK_DOWN  = 4;
const char MASK_LEFT  = 8;

char char_to_mask(char ch) {
    switch (ch) {
    case '+':
        return 15;
    case '-':
        return MASK_LEFT | MASK_RIGHT;
    case '|':
        return MASK_UP | MASK_DOWN;
    case '^':
        return MASK_UP;
    case '>':
        return MASK_RIGHT;
    case '<':
        return MASK_LEFT;
    case 'v':
        return MASK_DOWN;
    case 'L':
        return 15 ^ MASK_LEFT;
    case 'R':
        return 15 ^ MASK_RIGHT;
    case 'U':
        return 15 ^ MASK_UP;
    case 'D':
        return 15 ^ MASK_DOWN;
    case '*':
        return 0;
    default:
        assert(false);
    }
    return 179;
}

char mask_shift(char mask, int dim) {
    return ((mask << dim) | (mask >> (4 - dim))) & 15;
}

bool has(int dim, char mask, char sub) {
    return (mask_shift(mask, dim) & sub) == sub;
}


int main() {
    int n, m;
    scanf("%d %d\n", &n, &m);
    vector<vector<char>> field(n);
    
    for (int i = 0; i != n; ++i) {
        field[i].resize(m + 2);
        fgets(field[i].data(), m + 2, stdin);
        field[i].resize(m);
        for (char& ch: field[i])
            ch = char_to_mask(ch);
    }

    int xt, yt, xm, ym;
    scanf("%d %d\n%d %d", &xt, &yt, &xm, &ym);
    --xt, --yt, --xm, --ym;

    vector<vector<int>> graph(4 * maxn * maxn);
    auto add_edge = [&graph](int id1, int id2) {
        graph[id1].push_back(id2);
        graph[id2].push_back(id1);
    };
    for (int dim = 0; dim != 4; ++dim) {
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != m; ++j) {
                graph[get_id(dim, i, j)].push_back(get_id((dim + 1) % 4, i, j));
            }

        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (i != 0 and has(dim, field[i][j], MASK_UP) and has(dim, field[i - 1][j], MASK_DOWN))
                    add_edge(get_id(dim, i, j), get_id(dim, i - 1, j));
                if (j != 0 and has(dim, field[i][j], MASK_LEFT) and has(dim, field[i][j - 1], MASK_RIGHT))
                    add_edge(get_id(dim, i, j), get_id(dim, i, j - 1));
            }
        }
    }

    vector<size_t> times(4 * maxn * maxn, SIZE_MAX);
    times[get_id(0, xt, yt)] = 0;
    
    std::queue<int> ids;
    ids.push(get_id(0, xt, yt));

    while (not ids.empty()) {
        for (int i = 0; i != 4; ++i)
            if (times[get_id(i, xm, ym)] != SIZE_MAX)
            break; 
        
        int upp = ids.front();
        ids.pop();

        for (int v: graph[upp])
            if (times[v] == SIZE_MAX) {
                times[v] = times[upp] + 1;
                ids.push(v);
            }
    }
    size_t ans = SIZE_MAX;
    for (int i = 0; i != 4; ++i)
        ans = min(ans, times[get_id(i, xm, ym)]);

    if (ans == SIZE_MAX)
        cout << "-1\n";
    else
        cout << ans << "\n";

    
    return 0;
}