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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<int> f(n);
    for (int& x: f)
        x = input<int>() - 1;

    std::map<int, vector<int>> by_val;
    
    bool fail = false;
    for (int i = 0; i != n; ++i) {
        if (f[f[i]] != f[i])
            fail = true;
        
        by_val[f[i]].push_back(i);
    }

    if (fail) {
        cout << "-1\n";
        return 0;
    }

    int m = by_val.size();
    vector<int> g(n, -1), h(m, -1);

    int i = 0;
    for (const auto& elem: by_val) {
        h[i] = elem.first;
        for (auto x: elem.second)
            g[x] = i;

        i += 1;
    }
        
    cout << m << "\n";
    for (int x: g)
        cout << x + 1 << " ";
    cout << "\n";
    for (int x: h)
        cout << x + 1 << " ";
    cout << "\n";
    
    return 0;
}