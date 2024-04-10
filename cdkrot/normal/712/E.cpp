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

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

typedef double FFF;

struct OBJ {
    bool neutral;
    FFF A;
    FFF B;

    OBJ() {
        neutral = true;
    }
    OBJ(FFF prob) {
        neutral = false;
        A = B = prob;
    }
    
    OBJ operator+(OBJ other) const {
        if (neutral)
            return other;
        if (other.neutral)
            return *this;
        
        OBJ res;
        res.neutral = false;
        res.A = A * other.A / (1 - (1 - other.A) * B);
        res.B = other.B + (1 - other.B) * (B * other.A) / (1 - B * (1 - other.A));//1 - (1 - B) * (1 - other.B) / (1 - B * (1 - other.A));
        return res;
    }
};

const int MAXN = 110 * 1000;
OBJ tree[4 * MAXN];

#define set set_tree
#define get get_tree

OBJ get(int node, int node_l, int node_r, int l, int r) {
    if (l <= node_l and node_r <= r)
        return tree[node];
    else if (node_r <= l or r <= node_l)
        return OBJ();
    else {
        int m = node_l + (node_r - node_l) / 2;
        return get(2 * node + 1, node_l, m, l, r)
             + get(2 * node + 2, m, node_r, l, r);
    }
}

void set(int node, int node_l, int node_r, int pos, OBJ val) {
    if (node_l == node_r - 1) {
        assert(pos == node_l);
        tree[node] = val;
    } else {    
        int m = node_l + (node_r - node_l) / 2;
        if (pos < m)
            set(2 * node + 1, node_l, m, pos, val);
        else
            set(2 * node + 2, m, node_r, pos, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << std::fixed;
    cout.precision(10);
    int n, q;
    cin >> n >> q;
/*    OBJ a(1.0/3.0);
    OBJ b(1.0/2.0);
    OBJ c(2.0/3.0);*/
    for (int i = 0; i != n; ++i) {
        int a = input<int>();
        int b = input<int>();
        set(0, 0, n, i, OBJ(FFF(a) / b));
    }
    for (int i = 0; i != q; ++i) {
        if (input<int>() == 1) {
            int i, a, b;
            cin >> i >> a >> b, --i;
            set(0, 0, n, i, OBJ(FFF(a) / b));
        } else {
            int l, r;
            cin >> l >> r, --l, --r;
            auto res = get(0, 0, n, l, r + 1);
            cout << res.A << "\n";
        }
    }
    
    return 0;
}