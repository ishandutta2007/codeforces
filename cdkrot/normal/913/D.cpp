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

struct ev_t {
    int mx;
    int id;
    int tm;

    bool operator<(const ev_t& other) const {
        return mx < other.mx;
    }
};

std::mt19937 rnd(size_t(new char()));

struct node {
    node();
    node(int64_t el, int st) {
        elem = el;
        stat = st;
        l = r = nullptr;
        prio = rnd();
        recalc();
    }
    void recalc() {
        sum = elem;
        cnt = 1;

        if (l)
            sum += l->sum, cnt += l->cnt;
        if (r)
            sum += r->sum, cnt += r->cnt;
    }
    
    int64_t elem;
    int stat;
    int cnt;
    int64_t sum;
    uint32_t prio;
    node* l;
    node* r;
};

node* merge(node* a, node* b) {
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    if (a->prio > b->prio) {
        a->r = merge(a->r, b);
        a->recalc();
        return a;
    } else {
        b->l = merge(a, b->l);
        b->recalc();
        return b;
    }
}

int size(node* n) {
    if (n == nullptr)
        return 0;
    return n->cnt;
}

pair<node*, node*> split(node* root, int k) {
    if (root == nullptr)
        return make_pair(nullptr, nullptr);

    if (size(root->l) >= k) {
        auto spl = split(root->l, k);
        root->l = spl.second;
        root->recalc();

        return make_pair(spl.first, root);
    } else {
        auto spl = split(root->r, k - 1 - size(root->l));
        root->r = spl.first;
        root->recalc();

        return make_pair(root, spl.second);
    }
}


pair<node*, node*> split_key(node* root, int64_t key) {
    if (root == nullptr)
        return make_pair(nullptr, nullptr);

    if (root->elem >= key) {
        auto spl = split_key(root->l, key);
        root->l = spl.second;
        root->recalc();

        return make_pair(spl.first, root);
    } else {
        auto spl = split_key(root->r, key);
        root->r = spl.first;
        root->recalc();

        return make_pair(root, spl.second);
    }
}

void walk(node* root, int& lim) {
    if (root == nullptr)
        return;

    walk(root->l, lim);

    if (lim > 0) {
        --lim;
        cout << root->stat + 1 << " ";
    }

    walk(root->r, lim);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int T = input<int>();

    vector<ev_t> lst(n);
    for (int i = 0; i != n; ++i)
        cin >> lst[i].mx >> lst[i].tm, lst[i].id = i;


    sort(ALL(lst));
    node* root = nullptr;

    int ans = n;
    int ptr = n - 1;
    
    while (ans != 0) {
        while (ptr != -1 and lst[ptr].mx == ans) {
            auto spl = split_key(root, lst[ptr].tm);
            root = merge(spl.first, merge(new node(lst[ptr].tm, lst[ptr].id), spl.second));

            --ptr;
        }

        auto spl = split(root, ans);
        bool ok = (size(spl.first) == ans and spl.first->sum <= T);
        root = merge(spl.first, spl.second);
        if (ok)
            break;
        else
            ans -= 1;
    }

    cout << ans << "\n";
    cout << ans << "\n";
    int lim = ans;
    walk(root, lim);

    
    return 0;
}