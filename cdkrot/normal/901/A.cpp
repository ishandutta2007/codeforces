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
    vector<int> seq(1 + input<int>());
    input_seq(ALL(seq));

    int i = 0;
    while (i + 1 < SZ(seq) and (seq[i] == 1 or seq[i + 1] == 1))
        ++i;

    if (i + 1 == SZ(seq)) {
        cout << "perfect\n";
        return 0;
    }

    vector<int> a, b;
    for (int ptr = 0; ptr != i; ++ptr) {
        int t = SZ(a) - 1;
        for (int j = 0; j != seq[ptr]; ++j)
            a.push_back(t), b.push_back(t);
    }

    
    int lst = SZ(a) - 1;
    int nw = SZ(a);
    for (int j = 0; j != seq[i]; ++j)
        a.push_back(lst), b.push_back(lst);

    for (int j = 0; j != seq[i + 1]; ++j)
        a.push_back(nw);
    for (int j = 0; j != seq[i + 1]; ++j)
        b.push_back(nw + (j % 2));

    for (int ptr = i + 2; ptr != SZ(seq); ++ptr) {
        int t = SZ(a) - 1;
        for (int j = 0; j != seq[ptr]; ++j)
            a.push_back(t), b.push_back(t);
    }

    cout << "ambiguous\n";
    for (int elem: a)
        cout << 1 + elem << " ";
    cout << "\n";

    for (int elem: b)
        cout << 1 + elem << " ";
    cout << "\n";
    
    return 0;
}