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

int dp[100][100][100][3];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    string st = input<string>();

    vector<int> pos[3];
    for (int i = 0; i != n; ++i)
        if (st[i] == 'V')
            pos[0].push_back(i);
        else if (st[i] == 'K')
            pos[1].push_back(i);
        else
            pos[2].push_back(i);

    const int num_v = pos[0].size();
    const int num_k = pos[1].size();
    const int num_t = pos[2].size();
    
    for (int i = 0; i != 100; ++i)
        for (int j = 0; j != 100; ++j)
            for (int k = 0; k != 100; ++k)
                for (int l = 0; l != 3; ++l)
                    dp[i][j][k][l] = TYPEMAX(int);

    dp[0][0][0][2] = 0;

    auto relax = [](int& old, int nw) {old = min(old, nw);};
    auto get_pos = [&pos](int i, int j, int k, int sel) {
        int old = pos[sel][(sel == 0 ? i : (sel == 1 ? j : k))];
        int delta = 0;
        
        for (int a = 0; a != i; ++a)
            delta += pos[0][a] > old;
        for (int a = 0; a != j; ++a)
            delta += pos[1][a] > old;
        for (int a = 0; a != k; ++a)
            delta += pos[2][a] > old;

        return old + delta;
    };
    
    for (int i = 0; i <= num_v; ++i)
        for (int j = 0; j <= num_k; ++j)
            for (int k = 0; k <= num_t; ++k)
                for (int l = 0; l != 3; ++l)
                    if (dp[i][j][k][l] != TYPEMAX(int))
                        for (int nl = 0; nl != 3; ++nl)
                            if ((i != num_v or nl != 0) and (j != num_k or nl != 1) and (k != num_t or nl != 2))
                                if (not (l == 0 and nl == 1)) // VK
                                    relax(dp[i + (nl == 0)][j + (nl == 1)][k + (nl == 2)][nl],
                                          dp[i][j][k][l] + get_pos(i, j, k, nl) - (i + j + k));

    cout << min(min(dp[num_v][num_k][num_t][0], dp[num_v][num_k][num_t][1]), dp[num_v][num_k][num_t][2]) << "\n";
    
    return 0;
}