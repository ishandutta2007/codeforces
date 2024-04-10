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

int get_type(char ch) {
    switch (ch) {
    case '<':
        return 1;
    case '(':
        return 2;
    case '[':
        return 3;
    case '{':
        return 4;
        
    case '>':
        return -1;
    case ')':
        return -2;
    case ']':
        return -3;
    case '}':
        return -4;
    default:
        return 0;
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str = input<string>();
    
    uint32_t ans = 0;
    vector<int> stack;
    for (uint32_t i = 0; i != str.size(); ++i) {
        int tp = get_type(str[i]);
        assert(tp != 0);
        if (tp > 0)
            stack.push_back(tp);
        else {
            if (stack.empty()) {
                ans = UINT32_MAX;
                break;
            }
            
            if (stack.back() != -tp)
                ++ans;
            stack.pop_back();
        }
    }

    if (not stack.empty())
        ans = UINT32_MAX;
    
    if (ans == UINT32_MAX)
        cout << "Impossible\n";
    else
        cout << ans << "\n";
    return 0;
}