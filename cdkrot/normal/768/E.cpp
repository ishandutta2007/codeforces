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

int mex(const vector<int>& theset) {
    vector<char> presence(SZ(theset) + 1);
    for (int x: theset)
        if (x < SZ(presence))
            presence[x] = 1;

    int pos = 0;
    while (presence[pos])
        ++pos;
    return pos;
}

const int mx = 12;

struct marr {
    int elems[mx];
    int sz = 0;

    bool operator<(const marr& other) const {
        for (int i = 0; i != min(sz, other.sz); ++i)
            if (elems[i] < other.elems[i])
                return true;
            else if (elems[i] > other.elems[i])
                return false;

        if (sz < other.sz)
            return true;
        return false;
    }

    bool operator==(const marr& other) const {
        if (sz != other.sz)
            return false;
        for (int i = 0; i != sz; ++i)
            if (elems[i] != other.elems[i])
                return false;
        return true;
    }

    void push_back(int elem) {
        LASSERT(sz != mx);
        elems[sz++] = elem;
    }
};

vector<marr> glist;

vector<int> f = {0, 1,1,2,2,2,3,3,3,3,4,4,4,4,4,5,5,5,5,5,5,6,6,6,6,6,6,6,7,7,7,7,7,7,7,7,8,8,8,8,8,8,8,8,8,9,9,9,9,9,9,9,9,9,9,10,10,10,10,10,10};

void brute(marr cur, int sum, int min_pos) {
    if (min_pos <= 60)
        brute(cur, sum, min_pos + 1);
    
    if (sum + min_pos <= 60) {
        cur.push_back(min_pos);
        glist.push_back(cur);
        brute(cur, sum + min_pos, min_pos + 1);
    }
}

int dp[62][140000];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int xr = 0;
    for (int n = input<int>(); n != 0; --n) {
        xr = xr xor f[input<int>()];
    }
    cout << (xr ? "NO\n" : "YES\n");
    return 0;

    // code here.
    glist.push_back(marr());
    brute(marr(), 0, 1);
    
    std::sort(ALL(glist));
    assert(glist.size() < 140000);
    
    for (int i = 0; i != 140000; ++i)
        dp[0][i] = 0; // lose

    for (int k = 1; k <= 60; ++k)
        for (int cur_set = 0; cur_set != (int)glist.size(); ++cur_set) {
            vector<int> the_set;

            int ptr = 0;
            for (int tr = 1; tr <= k; ++tr) {
                if (ptr != glist[cur_set].sz and glist[cur_set].elems[ptr] == tr)
                    ++ptr;
                else {
                    marr nw = glist[cur_set];
                    nw.push_back(tr);
                    std::sort(nw.elems, nw.elems + nw.sz);
                    assert(std::unique(nw.elems, nw.elems + nw.sz) == nw.elems + nw.sz);

                    auto it = std::lower_bound(glist.begin(), glist.end(), nw);
                    if (it != glist.end() and *it == nw)
                        the_set.push_back(dp[k - tr][it - glist.begin()]);
                }
            }
                

            dp[k][cur_set] = mex(the_set);
        }

    for (int i = 1; i <= 60; ++i)
        cout << dp[i][0] << ",";
    
    return 0;
}