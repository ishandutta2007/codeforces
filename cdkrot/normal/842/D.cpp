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

// SK
int allocator_pos = 0;
char allocator_memory[(int)2e8];
inline void * operator new ( size_t n ) {
    char *res = allocator_memory + allocator_pos;
    allocator_pos += n;
    return (void *)res;
}
inline void operator delete ( void * ) noexcept { }
// END SK


struct node {
    node* go[2] = {NULL, NULL};
    int mex;
};

int get_mex(const vector<int>& seq) {
    vector<char> used(SZ(seq) + 1);
    for (int v: seq)
        if (v < SZ(used))
            used[v] = 1;

    int i = 0;
    for (; used[i]; ++i) {}

    return i;
}

node* build(vector<int>& seq, int cur) {
    node* res = new node();

    res->mex = get_mex(seq);
    
    if (cur == -1) {
        return res;
    } else {
        vector<int> s[2];
        for (int elem: seq)
            if (elem & (1 << cur))
                s[1].push_back(elem ^ (1 << cur));
            else
                s[0].push_back(elem);

        res->go[0] = build(s[0], cur - 1);
        res->go[1] = build(s[1], cur - 1);

        return res;
    }
}

int solve(node* root, int mask, int cur) {
    if (cur == -1)
        return root->mex;
    else {
        node* go[2] = {root->go[0], root->go[1]};
        if (mask & (1 << cur))
            std::swap(go[0], go[1]);

        if (go[0]->mex == (1 << cur))
            return (1 << cur) + solve(go[1], mask, cur - 1);
        else
            return solve(go[0], mask, cur - 1);
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int m = input<int>();

    vector<int> seq(n);
    input_seq(ALL(seq));

    node* root = build(seq, 18);

    int cur_mex = 0;
    for (int i = 0; i != m; ++i) {
        cur_mex ^= input<int>();
        cout << solve(root, cur_mex, 18) << "\n";
    }
    
    return 0;
}