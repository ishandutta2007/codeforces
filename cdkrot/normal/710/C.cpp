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
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = input<int>();
    assert(n % 2 == 1);
    if (n == 1)
        cout << "1\n";
    else {
        vector<int> nums[2];
        for (int i = 1; i <= n * n; ++i)
            nums[i % 2].push_back(i);
        
        vector<vector<int>> data(n, vector<int>(n));
        for (int i = 0; i != n; ++i)
            for (int j = 0; j != n; ++j) {
                int x = i - n / 2;
                int y = j - n / 2;
                int mode = 179;
                if (max(abs(x), abs(y)) <= 1)
                    mode = (abs(x) + abs(y) < 2);
                else {
                    int radius = max(abs(x), abs(y));
                    int delta4 = radius;
                    if (delta4 % 2 == 0) {// even
                        if (abs(x) == abs(y))
                            mode = 1;
                        delta4 -= 1;
                    }
                    
                    if (mode == 179) {
                        if (abs(x) == radius)
                            mode = (0 <= y and y < delta4);
                        else
                            mode = (0 <= x and x < delta4);
                    }
                }

                assert(not nums[mode].empty());
                data[i][j] = nums[mode].back(); nums[mode].pop_back();
            }
        
        for (int i = 0; i != n; ++i, cout << "\n")
            for (int j = 0; j != n; ++j, cout << " ")
                cout << data[i][j];
    }

    
    return 0;
}