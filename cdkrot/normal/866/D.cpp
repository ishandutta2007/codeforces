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

#ifndef LOCAL
std::mt19937 rnd(size_t(new char()));
#else
std::mt19937 rnd(228);
#endif

struct node {
    node(int64_t xval) {
        left = right = NULL;
        val = xval;
        prio = rnd();
        cnt = 1;
    }
    
    node* left;
    node* right;
    
    int64_t val;
    uint32_t prio;
    int cnt;
};

void recalc(node* root) {
    root->cnt = 1;
    if (root->left)
        root->cnt += root->left->cnt;
    if (root->right)
        root->cnt += root->right->cnt;
}

node* merge(node* a, node* b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    if (a->prio >= b->prio) {
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
    if (not root)
        return make_pair<node*, node*>(NULL, NULL);

    int lsz = (root->left ? root->left->cnt : 0);

    if (lsz >= cnt) {
        auto spl = split(root->left, cnt);
        root->left = spl.second;
        recalc(root);
        return make_pair(spl.first, root);
    } else {
        auto spl = split(root->right, cnt - 1 - lsz);
        root->right = spl.first;
        recalc(root);
        return make_pair(root, spl.second);
    }
}

// >, <=
pair<node*, node*> split_val(node* root, int64_t val) {
    if (not root)
        return make_pair<node*, node*>(NULL, NULL);

    if (root->val > val) {
        auto spl = split_val(root->right, val);
        root->right = spl.first;
        recalc(root);
        return make_pair(root, spl.second);
    } else {
        auto spl = split_val(root->left, val);
        root->left = spl.second;
        recalc(root);
        return make_pair(spl.first, root);
    }
}

node* get_k(node* root, int k) {
    int lsz = (root->left ? root->left->cnt : 0);

    if (k < lsz)
        return get_k(root->left, k);
    else if (k == lsz)
        return root;
    else
        return get_k(root->right, k - 1 - lsz);
}

void print(node* root, vector<int64_t>& out) {
    if (not root)
        return;
    print(root->left, out);
    out.push_back(root->val);
    print(root->right, out);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<int> pr(n);
    input_seq(ALL(pr));

    int64_t dp0 = 0;
    node* deltas = NULL;

#ifdef LOCAL
    vector<vector<int>> dp(n);
    for (int i = 0; i != n; ++i) {
        dp[i].resize(i + 2);
        if (i == 0)
            dp[i] = {0, -pr[i]};
        else {
            for (int j = 0; j <= i + 1; ++j) {
                dp[i][j] = TYPEMIN(int);
                if (j <= i)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                if (j + 1 <= i)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + pr[i]);
                if (j >= 1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - pr[i]);
            }
        }
    }
#endif
    
    deltas = new node(-pr[0]);
    
    for (int i = 1; i != n; ++i) {
        if (dp0 + get_k(deltas, 0)->val + pr[i] > dp0) {
            dp0 += get_k(deltas, 0)->val + pr[i];

            // <, >=
            auto spl = split_val(deltas, -pr[i]);

            spl.first  = split(spl.first, 1).second;
            spl.first  = merge(spl.first, new node(-pr[i]));
            spl.second = merge(new node(-pr[i]), spl.second);
            
            deltas = merge(spl.first, spl.second);
        } else {
            // <, >=
            auto spl = split_val(deltas, -pr[i]);

            spl.second = merge(new node(-pr[i]), spl.second);
            deltas = merge(spl.first, spl.second);
        }
#ifdef LOCAL
        for (int j = 0; j != SZ(dp[i]); ++j)
            cout << dp[i][j] << " ";
        cout << "\n";

        vector<int64_t> tmp;
        print(deltas, tmp);

        cout << dp0;
        int64_t cur = dp0;
        for (auto elem: tmp) {
            cur += elem;
            cout << " " << cur;
        }
        cout << "\n";
#endif
    }

    cout << dp0 << "\n";

    
    return 0;
}