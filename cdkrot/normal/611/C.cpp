// Copyright (C) 2015-16 Sayutin Dmitry.
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 3, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; If not, see <http://www.gnu.org/licenses/>.

#include <iostream>
#include <vector>
#include <map>
#include <stdint.h>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <string>

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
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


int main() {
    uint32_t h, w;
    cin >> h >> w;
    cin.get();

    vector<string> field(h);
    for (uint32_t i = 0; i != h; ++i)
        std::getline(cin, field[i]);

    vector<vector<uint32_t>> prefix_sum1(h, vector<uint32_t>(w, 0));
    vector<vector<uint32_t>> prefix_sum2(h, vector<uint32_t>(w, 0));
    
    for (uint32_t i = 0; i != h; ++i)
        for (uint32_t j = 0; j != w; ++j) {
            if (i != 0) {
                prefix_sum1[i][j] += prefix_sum1[i - 1][j];
                if (field[i][j] == '.' and field[i - 1][j] == '.')
                    ++prefix_sum1[i][j];
            }
            if (j != 0) {
                prefix_sum2[i][j] += prefix_sum2[i][j - 1];
                if (field[i][j] == '.' and field[i][j - 1] == '.')
                    ++prefix_sum2[i][j];
            }
            if (i != 0 and j != 0) {
                prefix_sum1[i][j] += prefix_sum1[i][j - 1];
                prefix_sum2[i][j] += prefix_sum2[i - 1][j];
                prefix_sum1[i][j] -= prefix_sum1[i - 1][j - 1];
                prefix_sum2[i][j] -= prefix_sum2[i - 1][j - 1];
            }
        }
    
    for (uint32_t q = input<uint32_t>(); q != 0; --q) {
        uint32_t x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        uint32_t ans = 0;
        //
        ans += prefix_sum1[x2][y2];
        ans -= prefix_sum1[x1][y2];
        ans += (y1 == 0 ? 0 : prefix_sum1[x1][y1 - 1]);
        ans -= (y1 == 0 ? 0 : prefix_sum1[x2][y1 - 1]);

        ans += prefix_sum2[x2][y2];
        ans -= prefix_sum2[x2][y1];
        ans += (x1 == 0 ? 0 : prefix_sum2[x1 - 1][y1]);
        ans -= (x1 == 0 ? 0 : prefix_sum2[x1 - 1][y2]);
                
        cout << ans << "\n";
    }
    
    return 0;
}