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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (cin.peek() == '\n')
        cin.get();

    vector<vector<int>> data(n, vector<int>(n));
    int a1 = 100500;
    int a2 = -100500;
    int b1 = 100500;
    int b2 = -100500;
    
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j) {
            char ch = input<char>();
            assert(ch >= '0' and ch <= '4');
            data[i][j] = ch - '0';
            
            if (data[i][j] >= 3) {
                a1 = min(a1, i);
                a2 = max(a2, i + 1);
                b1 = min(b1, j);
                b2 = max(b2, j + 1);
            }
        }

    auto inside = [a1, a2, b1, b2](int i, int j) {
        return a1 <= i and i <= a2 and b1 <= j and j <= b2;
    };
    
    for (int i = 0; i != n; ++i)//,cout << "\n")
        for (int j = 0; j != n; ++j) {
            int exp = 0;
            exp += inside(i, j);
            exp += inside(i + 1, j);
            exp += inside(i + 1, j + 1);
            exp += inside(i, j + 1);
//            cout << exp;
//            continue;
            if (exp != data[i][j]) {
                cout << "No\n";
                return 0;
            }
        }

    cout << "Yes\n";
    return 0;
}