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

struct node {
    node() {
        go[0] = go[1] = nullptr;
    }

    node* go[2];
    int cnt = 0;
};

int cnt_of(node* v) {
    return (v == NULL ? 0 : v->cnt);
}

int get_best(node* root, int val) {
    node* cur = root;
    int cur_val = 0;
    
    for (int j = 30; j >= 0; --j) {
        int c = !!(val & (1 << j));

        if (cnt_of(cur->go[c]) != 0) {
            cur_val |= (c << j);
            cur = cur->go[c];
        } else {
            cur_val |= ((1 - c) << j);
            cur = cur->go[1 - c];
        }
    }
    
    return cur_val;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();

    vector<int> a(n);
    input_seq(ALL(a));

    node* root = new node();
    root->cnt = n;
    
    for (int i = 0; i != n; ++i) {
        node* cur = root;
        int p_i = input<int>();

        for (int j = 30; j >= 0; --j) {
            int c = !!(p_i & (1 << j));

            if (cur->go[c] == NULL)
                cur->go[c] = new node();

            cur = cur->go[c];
            cur->cnt += 1;
        }
    }

    for (int i = 0; i != n; ++i) {
        int v = a[i];

        int best = get_best(root, v);
        root->cnt -= 1;

        node* cur = root;
        for (int j = 30; j >= 0; --j) {
            int c = !!(best & (1 << j));
            cur = cur->go[c];
            cur->cnt -= 1;
        }
        
        cout << (best xor v) << " ";
    }

    cout << "\n";
    
    return 0;
}