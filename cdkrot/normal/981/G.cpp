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

const int mod = 998244353;

int add(int a, int b) {return a + b >= mod ? a + b - mod : a + b;}
int mult(int a, int b) {return (int64_t(a) * b) % mod;}

const int max_n = 2.1e5;

struct modif_t {
    int a;
    int b;
};

const modif_t trivial = {1, 0};

int apply(modif_t modif, int val) {
    return add(mult(modif.a, val), modif.b);
}

int massive_apply(modif_t modif, int sum, int cnt) {
    return add(mult(modif.a, sum), mult(modif.b, cnt));
}

modif_t chain(modif_t m1, modif_t m2) {
    modif_t m3;
    m3.a = mult(m1.a, m2.a);
    m3.b = add(mult(m2.a, m1.b), m2.b);

    return m3;
}

vector<int> tree(4 * max_n);
vector<modif_t> mods(4 * max_n, trivial);

void push(int no, int nl, int nr) {
    tree[no] = massive_apply(mods[no], tree[no], nr - nl);

    if (nl != nr - 1) {
        mods[2 * no + 1] = chain(mods[2 * no + 1], mods[no]);
        mods[2 * no + 2] = chain(mods[2 * no + 2], mods[no]);
    }

    mods[no] = trivial;
}

void recalc(int no, int nl, int nr) {
    LASSERT(nl != nr - 1);
    LASSERT(mods[no].a == trivial.a and mods[no].b == trivial.b);

    int mi = nl + (nr - nl) / 2;
    push(2 * no + 1, nl, mi);
    push(2 * no + 2, mi, nr);

    tree[no] = add(tree[2 * no + 1],
                   tree[2 * no + 2]);
}

void do_op_(int no, int nl, int nr, int l, int r, modif_t modif) {
    if (r <= nl or nr <= l)
        return; // miss

    push(no, nl, nr);
    
    if (l <= nl and nr <= r) {
        mods[no] = modif;
        return;
    }

    int mi = nl + (nr - nl) / 2;
    do_op_(2 * no + 1, nl, mi, l, r, modif);
    do_op_(2 * no + 2, mi, nr, l, r, modif);

    recalc(no, nl, nr);
}

void do_op(int no, int nl, int nr, int l, int r, modif_t modif) {
#ifdef LOCAL
    cerr << no << " " << nl << " " << nr << " " << l << " " << r << " " << modif.a << " " << modif.b << "\n";
#endif
    do_op_(no, nl, nr, l, r, modif);
}

int get_sum(int no, int nl, int nr, int l, int r) {
    if (r <= nl or nr <= l)
        return 0;

    push(no, nl, nr);
    
    if (l <= nl and nr <= r)
        return tree[no];

    int mi = nl + (nr - nl) / 2;
    return add(get_sum(2 * no + 1, nl, mi, l, r),
               get_sum(2 * no + 2, mi, nr, l, r));
}


struct cmp_first {
    bool operator()(pair<int, int> a, pair<int, int> b) const {
        return a.first < b.first;
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n, q;
    cin >> n >> q;

    vector<set<pair<int, int>, cmp_first>> the_blad(n);

    for (int it = 0; it != q; ++it) {
        if (input<int>() == 1) {
            // new op

            int l, r, x;
            cin >> l >> r >> x;
            --l, --r, --x;

            auto& blad = the_blad[x];
            
            while (l <= r) {
                auto it = blad.upper_bound(make_pair(l, -10000000));

                if (it != blad.begin() and std::prev(it)->second >= l) {
                    int next = min(r, std::prev(it)->second);
                    do_op(0, 0, n, l, next + 1, modif_t {2, 0}); //bayan.
                    l = next + 1;

                    continue;
                }

                it = blad.lower_bound(make_pair(l, -10000));
                int next;
                if (it == blad.end())
                    next = r;
                else
                    next = min(r, it->first - 1);

                do_op(0, 0, n, l, next + 1, modif_t {1, 1});

                // add [l; next].
                {
                    int the_l = l;
                    int the_r = next;
                    it = blad.lower_bound(make_pair(the_r + 1, -10000));
                    if (it != blad.end() and it->first == the_r + 1) {
                        the_r = it->second;
                        blad.erase(it);
                    }

                    it = blad.lower_bound(make_pair(the_l, -1000));
                    if (it != blad.begin() and std::prev(it)->second == the_l - 1) {
                        the_l = std::prev(it)->first;
                        blad.erase(std::prev(it));
                    }

                    blad.emplace(the_l, the_r);
                }
                l = next + 1;
            }
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;

            cout << get_sum(0, 0, n, l, r + 1) << "\n";
        }
    }
    
    return 0;
}