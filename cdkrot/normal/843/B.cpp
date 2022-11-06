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
#include <time.h>


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

int n;

#ifdef LOCAL
int nexts[5] = {-1, 5, 2, 1, 4};
int values[5] = {97, 58, 16, 81, 79};
#endif

pair<int, int> request(int pos) {
    assert(pos >= 1);
    assert(pos <= n);
    
    cout << "? " << pos << std::endl;

#ifdef LOCAL
    int val = values[pos - 1];
    int next = nexts[pos - 1];
#else
    int val = input<int>();
    int next = input<int>();
#endif
    
    if (val == -1)
        exit(0);
    
    return {val, next};
}

void ans(int val) {
    cout << "! " << val << std::endl;
    exit(0);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    n = input<int>();
    int start = input<int>();
    int x = input<int>();

    vector<int> list(n);
    std::iota(ALL(list), 1);

    std::mt19937 rnd(time(0));
    std::shuffle(ALL(list), rnd);

    list.resize(min(SZ(list), 1000));

    int best_val = request(start).first;
    int best_pos = start;

    if (best_val >= x)
        ans(best_val);
    
    for (int i = 0; i != SZ(list); ++i) {
        int value = request(list[i]).first;
        
        if (value <= x and best_val < value)
            best_val = value, best_pos = list[i];
    }

    int cur_pos = best_pos;
    for (; cur_pos != -1 and request(cur_pos).first < x; cur_pos = request(cur_pos).second) {}

    ans(cur_pos == -1 ? -1 : request(cur_pos).first);
    
    return 0;
}