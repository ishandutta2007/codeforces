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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string ans = "";
    size_t n = input<size_t>();
    std::multiset<int> theset;
    for (size_t i = 0; i != n; ++i) {
        string op = input<string>();
        int arg;
        
        if (op != "removeMin")
            arg = input<int>();

        if (op == "insert")
            theset.insert(arg);
        if (op == "removeMin") {
            if (theset.empty())
                ans += "insert 666\n";
            else
                theset.erase(theset.begin());
        }
        if (op == "getMin") {
            while (not theset.empty() and *(theset.begin()) < arg) {
                ans += "removeMin\n";
                theset.erase(theset.begin());
            }
            
            if (theset.empty() or *(theset.begin()) > arg) {
                ans += string("insert ") + std::to_string(arg) + string("\n");
                theset.insert(arg);
            }
        }
        ans += op;
        if (op != "removeMin")
            ans += " " + std::to_string(arg) + "\n";
        else
            ans += "\n";
    }
    cout << std::count(ans.begin(), ans.end(), '\n') << "\n";
    cout << ans;
    
    return 0;
}