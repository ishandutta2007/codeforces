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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    uint32_t n, p, q;
    cin >> n >> p >> q;

    string str = input<string>();
    
    for (uint32_t i = 0; i <= n; ++i)
        for (uint32_t j = 0; j <= n; ++j)
            if (p * i + q * j == n) {
                vector<string> spl;
                uint32_t st = 0;
                for (uint32_t k = 0; k != i; ++k)
                    spl.push_back(str.substr(st, p)), st += p;
                for (uint32_t k = 0; k != j; ++k)
                    spl.push_back(str.substr(st, q)), st += q;

                assert(st == n);
                cout << spl.size() << "\n";
                for (auto v: spl)
                    cout << v << "\n";
                
                return 0;
            }
    cout << "-1\n";
    
    return 0;
}