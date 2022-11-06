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

int char_to_int(char ch) {
    if (ch == '-')
        return 62;
    if (ch == '_')
        return 63;
    if ('0' <= ch and ch <= '9')
        return ch - '0';
    if ('A' <= ch and ch <= 'Z')
        return 10 + ch - 'A';
    if ('a' <= ch and ch <= 'z')
        return 36 + ch - 'a';
    assert(false);
}

#define LL long long

LL table[64];

int main() {
    for (int i = 0; i != 64; ++i)
        for (int j = 0; j != 64; ++j)
            for (int k = 0; k != 64; ++k)
            if ((i & j) == k)
                table[k] += 1;
    
    const LL md = 1000 * 1000 * 1000 + 7;
    LL ans = 1;
    string s = input<string>();
    
    for (char ch: s)
        ans = (ans * table[char_to_int(ch)]) % md;
    cout << ans << "\n";
}