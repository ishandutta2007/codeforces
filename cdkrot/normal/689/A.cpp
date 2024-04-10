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

char tmp[4][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'},
                  {' ', '0', ' '}};

typedef pair<int, int> pii;
pii id[9];


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 0; i != 4; ++i)
        for (int j = 0; j != 3; ++j)
            if (tmp[i][j] != ' ')
                id[tmp[i][j] - '0'] = make_pair(i, j);
    
    input<int>();
    string s = input<string>();
    int cnt = 0;
    for (int i = 0; i <= 9; ++i) {
        pii pos = id[i];
        for (int j = 1; j != s.size(); ++j) {
            pos.first += id[s[j] - '0'].first - id[s[j - 1] - '0'].first;
            pos.second += id[s[j] - '0'].second - id[s[j - 1] - '0'].second;
            if (pos.first < 0 or pos.first >= 4 or pos.second < 0 or pos.second >= 3 or tmp[pos.first][pos.second] == ' ')
                goto fail;
        }
        cnt += 1;
    fail:;
    }

    assert(cnt >= 1);
    cout << (cnt > 1 ? "NO\n" : "YES\n");
    
    return 0;
}