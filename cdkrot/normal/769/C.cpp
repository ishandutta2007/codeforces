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

// D L R U
int da[4] = {1,  0, 0, -1};
int db[4] = {0, -1, 1,  0};
const char* mp = "DLRU";

#define impossible()  {cout << "IMPOSSIBLE\n";  return 0;}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n, m, k;
    cin >> n >> m >> k;

    if (k % 2 == 1)
        impossible();
    
    vector<string> field(n);
    int a = -1, b = -1;
    for (int i = 0; i != n; ++i) {
        cin >> field[i];

        for (int j = 0; j != m; ++j)
            if (field[i][j] == 'X')
                field[i][j] = '.', a = i, b = j;
    }

    int t = 0;
    for (; t != 4; ++t)
        if (a + da[t] >= 0 and a + da[t] < n and b + db[t] >= 0 and b + db[t] < m and field[a + da[t]][b + db[t]] == '.')
            break;

    if (t == 4)
        impossible();

    vector<vector<int>> dist(n, vector<int>(m, TYPEMAX(int)));
    std::queue<pair<int, int>> qs;
    qs.emplace(a, b);
    dist[a][b] = 0;
    while (not qs.empty()) {
        auto acur = qs.front().first;
        auto bcur = qs.front().second;
        qs.pop();

        for (t = 0; t != 4; ++t)
            if (acur + da[t] >= 0 and acur + da[t] < n and bcur + db[t] >= 0 and bcur + db[t] < m
            and field[acur + da[t]][bcur + db[t]] == '.' and dist[acur + da[t]][bcur + db[t]] == TYPEMAX(int)) {
                dist[acur + da[t]][bcur + db[t]] = dist[acur][bcur] + 1;
                qs.emplace(acur + da[t], bcur + db[t]);
            }
    }

    string ans = "";
    for (int i = 0; i != k; ++i) {
        for (t = 0; t != 4; ++t)
            if (a + da[t] >= 0 and a + da[t] < n and b + db[t] >= 0 and b + db[t] < m
            and field[a + da[t]][b + db[t]] == '.' and dist[a + da[t]][b + db[t]] <= k - 1 - i)
                break;

        assert(t != 4);
        
        a += da[t];
        b += db[t];
        ans += mp[t];
    }

    cout << ans << "\n";
    
    return 0;
}