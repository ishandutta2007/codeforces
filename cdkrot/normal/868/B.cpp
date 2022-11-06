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
#include <tuple>


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

#define pb push_back
#define eb emplace_back


int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int h = input<int>() % 12;
    int m = input<int>();
    int s = input<int>();

    int t1 = input<int>() % 12;
    int t2 = input<int>() % 12;

    vector<int> obst;
    if (m != 0 or s != 0)
        obst.push_back(2 * h + 1); // h + 0.5
    else
        obst.push_back(2 * h);
    
    if (m % 5 != 0 or s != 0)
        obst.push_back(2 * (m / 5) + 1);
    else
        obst.push_back(2 * (m / 5));

    if (s % 5 != 0)
        obst.push_back(2 * (s / 5) + 1);
    else
        obst.push_back(2 * (s / 5));

    t1 *= 2;
    t2 *= 2;

    int cur;
    for (cur = t1; cur != t2; cur = (cur + 1) % 24) {
        if (std::find(ALL(obst), cur) != obst.end())
            break;
    }

    if (cur == t2) {
        cout << "Yes\n";
        return 0;
    }

    for (cur = t2; cur != t1; cur = (cur + 1) % 24) {
        if (std::find(ALL(obst), cur) != obst.end())
            break;
    }

    if (cur == t1 ){
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
    
    return 0;
}