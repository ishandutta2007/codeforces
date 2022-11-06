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

struct node {
    node(int key, int prio): key(key), sz(1), prio(prio), left(nullptr), right(nullptr) {}
    
    int key;
    int sz;
    int prio;
    
    node* left;
    node* right;
};

void recalc(node* a) {
    a->sz = 1;
    a->sz += (a->left ?  a->left->sz  : 0);
    a->sz += (a->right ? a->right->sz : 0);
}

node* merge(node* a, node* b) {
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    if (a->prio > b->prio) {
        a->right = merge(a->right, b);
        recalc(a);
        return a;
    } else {
        b->left = merge(a, b->left);
        recalc(b);
        return b;
    }
}

pair<node*, node*> split(node* root, int cnt) {
    if (root == nullptr)
        return {nullptr, nullptr};
    
    if ((root->left ? root->left->sz : 0) >= cnt) {
        auto spl = split(root->left, cnt);
        root->left = spl.second;
        recalc(root);
        
        return {spl.first, root};
    } else {
        auto spl = split(root->right, cnt - 1 - (root->left ? root->left->sz : 0));
        root->right = spl.first;
        recalc(root);

        return {root, spl.second};
    }
}

std::mt19937 rnd;

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int k = input<int>();

    node* root = nullptr;
    vector<int> ks(k);
    input_seq(ALL(ks));
    
    for (int i = 0; i != n; ++i)
        root = merge(root, new node(i, rnd()));

    int elem = 0;
    for (int i = 0; i != k; ++i) {
        int diepos = (elem + ks[i]) % root->sz;
        
        auto spl1 = split(root, diepos);
        auto spl2 = split(spl1.second, 1);

        elem = diepos;
        cout << spl2.first->key + 1 << " ";
        
        root = merge(spl1.first, spl2.second);
    }

    cout << "\n";
    
    return 0;
}