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

const int BLOCK = 300;
struct block_t {
    int clean = 63;
    
    int64_t ans = 0;

    int up_mod   = TYPEMAX(int);
    int down_mod = TYPEMIN(int);
    
    std::array<int, BLOCK> up, down;

    vector<int> uplist_gooddown, uplist_baddown, downlist_goodup, downlist_badup;

    vector<int64_t> uplist_gooddown_s, uplist_baddown_s, downlist_goodup_s, downlist_badup_s;
    
    block_t() {
        std::fill(ALL(up), TYPEMAX(int));
        std::fill(ALL(down), TYPEMIN(int));
    }
    
    void recalc() {
        if (clean == 0)
            return;
        clean = 0;
        
        ans = 0;
        
        uplist_gooddown.clear();
        uplist_baddown.clear();
        downlist_goodup.clear();
        downlist_badup.clear();

        for (int i = 0; i != BLOCK; ++i) {
            up[i] = min(up[i], up_mod);
            down[i] = max(down[i], down_mod);
            if (up[i] != TYPEMAX(int) and down[i] != TYPEMIN(int))
                ans += up[i] - down[i];

            if (down[i] != TYPEMIN(int))
                uplist_gooddown.push_back(up[i]);
            else
                uplist_baddown.push_back(up[i]);

            if (up[i] != TYPEMAX(int))
                downlist_goodup.push_back(down[i]);
            else
                downlist_badup.push_back(down[i]);
        }

        build(uplist_gooddown, uplist_gooddown_s);
        build(uplist_baddown, uplist_baddown_s);
        build(downlist_goodup, downlist_goodup_s);
        build(downlist_badup, downlist_badup_s);
    }

    void build(vector<int>& src, vector<int64_t>& out) {
        std::sort(ALL(src));
        out.clear();
        out.resize(SZ(src) + 1);
        
        for (int i = 0; i != SZ(src); ++i)
            out[i + 1] = out[i] + src[i];
    }
    
    void apply(int ind, int val) {
        clean = 63;
        if (val > 0)
            up[ind] = min(up[ind], val);
        if (val < 0)
            down[ind] = max(down[ind], val);
    }

    int get(int ind) {
        recalc();
        if (up[ind] == TYPEMAX(int) or down[ind] == TYPEMIN(int))
            return 0;
        else
            return up[ind] - down[ind];
    }

    void apply(int k) {
        if (k > 0)
            up_mod = min(up_mod, k), clean |= 1;
        else
            down_mod = max(down_mod, k), clean |= 2;
    }

    int64_t get_sum(const vector<int>& a, const vector<int64_t>& b) {
#ifdef LOCAL
        int64_t ans = 0;
        for (int val: a)
            if (val != TYPEMAX(int) and val != TYPEMIN(int))
                ans += val;
        return ans;
#else
        auto ilo = std::upper_bound(ALL(a), TYPEMIN(int)) - a.begin();
        auto ihi = std::lower_bound(ALL(a), TYPEMAX(int)) - a.begin();

        return b[ihi] - b[ilo];

#endif
    }

    int64_t get_sum(const vector<int>& a, const vector<int64_t>& b, int mn, int mx) {
#ifdef LOCAL
        int64_t ans = 0;
        for (int val: a)
            if (val < mn)
                ans += mn;
            else if (val > mx)
                ans += mx;
            else
                ans += val;
        return ans;
#else        
        auto ilo = std::lower_bound(ALL(a), mn) - a.begin();
        auto ihi = std::upper_bound(ALL(a), mx) - a.begin();

        return b[ihi] - b[ilo] + int64_t(mn) * ilo + int64_t(mx) * (SZ(a) - ihi);
#endif
    }
    
    int64_t get() {
        int64_t AAA = 0;
        
        if (clean == 0)
            return ans;
        else if (clean == 1) {
            AAA -= get_sum(downlist_goodup, downlist_goodup_s);
            AAA -= get_sum(downlist_badup, downlist_badup_s);
            AAA += get_sum(uplist_gooddown, uplist_gooddown_s, 0, up_mod);
#ifdef LOCAL
            recalc();
            cout << AAA << " -1- " << ans << "\n";
#endif
        } else if (clean == 2) {
            AAA += get_sum(uplist_gooddown, uplist_gooddown_s);
            AAA += get_sum(uplist_baddown, uplist_baddown_s);
            AAA -= get_sum(downlist_goodup, downlist_goodup_s, down_mod, 0);
#ifdef LOCAL
            recalc();
            cout << AAA << " -2- " << ans << "\n";
#endif
        } else if (clean == 3) {
            AAA += get_sum(uplist_gooddown, uplist_gooddown_s, 0, up_mod);
            AAA += get_sum(uplist_baddown, uplist_baddown_s, 0, up_mod);
            AAA -= get_sum(downlist_goodup, downlist_goodup_s, down_mod, 0);
            AAA -= get_sum(downlist_badup, downlist_badup_s, down_mod, 0);
#ifdef LOCAL
            recalc();
            cout << AAA << " -3- " << ans << "\n";
#endif
        } else {
            assert(false);
        }
        return AAA;
    }
};

const int maxn = 100 * 1000 + 10;
block_t blocks[(maxn + BLOCK - 1) / BLOCK];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    for (int i = 0; i < (maxn + BLOCK - 1) / BLOCK; ++i)
        blocks[i].recalc();
    
    for (int q = input<int>(); q != 0; --q) {
        int tp = input<int>();
        int l = input<int>();
        int r = input<int>() - 1;

        if (tp == 1) {
            int k = input<int>();

            int bl = l / BLOCK;
            int br = r / BLOCK;
            
            for (; l <= r and l % BLOCK != 0; ++l)
                blocks[bl].apply(l % BLOCK, k);
            blocks[bl].recalc();
            
            for (; l <= r and r % BLOCK != BLOCK - 1; --r)
                blocks[br].apply(r % BLOCK, k);
            blocks[br].recalc();

            for (; l <= r; l += BLOCK)
                blocks[l / BLOCK].apply(k);
        } else {
            int64_t ans = 0;
            for (; l <= r and l % BLOCK != 0; ++l)
                ans += blocks[l / BLOCK].get(l % BLOCK);
            for (; l <= r and r % BLOCK != BLOCK - 1; --r)
                ans += blocks[r / BLOCK].get(r % BLOCK);

            for (; l <= r; l += BLOCK)
                ans += blocks[l / BLOCK].get();

            cout << ans << "\n";
        }
    }
    
    return 0;
}