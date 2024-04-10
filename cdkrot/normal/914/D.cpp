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

const int max_n = 5 * 100 * 1000;

int tree[4 * max_n];

#define gcd(a, b) std::__gcd(a, b)

void build(int node, int nl, int nr, const vector<int>& src) {
    if (nl == nr - 1) {
        tree[node] = src[nl];
    } else {
        int mi = nl + (nr - nl) / 2;

        build(2 * node + 1, nl, mi, src);
        build(2 * node + 2, mi, nr, src);

        tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

void update(int node, int nl, int nr, int pos, int val) {
    if (nl == nr - 1) {
        LASSERT(nl == pos);
        tree[node] = val;
    } else {
        int mi = nl + (nr - nl) / 2;

        if (pos < mi)
            update(2 * node + 1, nl, mi, pos, val);
        else
            update(2 * node + 2, mi, nr, pos, val);
        
        tree[node] = gcd(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

void split(int node, int nl, int nr, int l, int r, vector<pair<int, pair<int, int>>>& outcome) {
    if (l <= nl and nr <= r)
        outcome.emplace_back(node, make_pair(nl, nr));
    else if (nr <= l or r <= nl)
        return;
    else {
        int mi = nl + (nr - nl) / 2;

        split(2 * node + 1, nl, mi, l, r, outcome);
        split(2 * node + 2, mi, nr, l, r, outcome);
    }
}

bool check(int node, int nl, int nr, int x) {
    if (nr - nl == 1)
        return true;
    else {
        int mi = nl + (nr - nl) / 2;

        if (tree[2 * node + 1] % x != 0 and tree[2 * node + 2] % x != 0)
            return false;

        if (tree[2 * node + 1] % x != 0)
            return check(2 * node + 1, nl, mi, x);
        else
            return check(2 * node + 2, mi, nr, x);
    }
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<int> seq(n);
    input_seq(ALL(seq));

    build(0, 0, n, seq);

    int q = input<int>();
    for (int i = 0; i != q; ++i) {
        if (input<int>() == 1) {
            int l = input<int>() - 1;
            int r = input<int>() - 1;
            int x = input<int>();

            vector<pair<int, pair<int, int>>> outcome, bad;
            split(0, 0, n, l, r + 1, outcome);

            for (auto elem: outcome)
                if (tree[elem.first] % x != 0)
                    bad.push_back(elem);

            if (bad.empty())
                cout << "YES\n";
            else if (bad.size() >= 2)
                cout << "NO\n";
            else {
                if (check(bad[0].first, bad[0].second.first, bad[0].second.second, x))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }    
        } else {
            int i = input<int>() - 1;
            int val = input<int>();
            update(0, 0, n, i, val);
        }
    }
    
    return 0;
}