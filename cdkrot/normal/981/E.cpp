// Copyright (C) 2018 Sayutin Dmitry.
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
#include <bitset>

using std::bitset;

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

vector<vector<int>> tree;

const int max_n = 10 * 1000 + 10;
bitset<max_n> ans;



void do_add(int no, int nl, int nr, int l, int r, int x) {
    if (l <= nl and nr <= r) {
        tree[no].push_back(x);
        return;
    }

    if (r <= nl or nr <= l)
        return;

    int mi = nl + (nr - nl) / 2;
    do_add(2 * no + 1, nl, mi, l, r, x);
    do_add(2 * no + 2, mi, nr, l, r, x);
}

void harvest(int no, int nl, int nr, bitset<max_n> cur) {
    for (int x: tree[no])
        cur = cur | (cur << x);

    if (nl == nr - 1)
        ans |= cur;
    else {
        int mi = nl + (nr - nl) / 2;
        harvest(2 * no + 1, nl, mi, cur);
        harvest(2 * no + 2, mi, nr, cur);
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int q = input<int>();

    tree.resize(4 * n);

    for (int i = 0; i != q; ++i) {
        int l, r, x;

        cin >> l >> r >> x;
        --l, --r;
        
        do_add(0, 0, n, l, r + 1, x);
    }

    bitset<max_n> bts;
    bts[0] = 1;
    harvest(0, 0, n, bts);

    vector<int> lst;
    for (int i = 1; i <= n; ++i)
        if (ans[i])
            lst.push_back(i);

    cout << SZ(lst) << "\n";
    for (int elem: lst)
        cout << elem << " ";
    cout << "\n";
    
    return 0;
}