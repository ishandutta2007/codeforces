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


struct dsu {
    dsu(int n) {
        par.resize(n);
        std::iota(ALL(par), 0);

        rk.resize(n);
    }

    int get(int v) {
        while (v != par[v])
            v = par[v];
        return v;
    }

    bool unite(int v, int u) {
        v = get(v);
        u = get(u);

        if (v == u)
            return false;

        if (not (rk[v] <= rk[u]))
            std::swap(v, u);

        set(par[v], u);
        if (rk[v] == rk[u])
            set(rk[u], rk[u] + 1);
        return true;
    }

    void set(int& ptr, int val) {
        log.emplace_back(&ptr, ptr);
        ptr = val;
    }

    int tm() {
        return log.size();
    }

    void revert(int tm) {
        while (log.size() > tm) {
            *(log.back().first) = log.back().second;
            log.pop_back();
        }
    }
    
    vector<int> par;
    vector<int> rk;

    vector<pair<int*, int>> log;
};

#include <tuple>
using std::tuple;
using std::get;

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    int m = input<int>();

    vector<tuple<int, int, int>> edg(m);
    for (int i = 0; i != m; ++i) {
        cin >> get<0>(edg[i]) >> get<1>(edg[i]) >> get<2>(edg[i]);

        --get<0>(edg[i]);
        --get<1>(edg[i]);
    }

    vector<vector<int>> lists(m);
    
    int q = input<int>();
    for (int i = 0; i != q; ++i) {
        for (int k = input<int>(); k != 0; --k)
            lists[input<int>() - 1].push_back(i);
    }

    vector<int> perm(m);
    iota(ALL(perm), 0);

    std::sort(ALL(perm), [&](int i, int j) {return get<2>(edg[i]) < get<2>(edg[j]);});

    dsu cmp(n);

    vector<char> ans(q, true);
    
    for (int i = 0; i != SZ(perm);) {
        int i0 = i;

        while (i != SZ(perm) and get<2>(edg[perm[i]]) == get<2>(edg[perm[i0]]))
            i += 1;

        std::map<int, vector<pair<int, int>>> lst;
        for (int t = i0; t != i; ++t)
            for (int rq: lists[perm[t]])
                lst[rq].emplace_back(get<0>(edg[perm[t]]), get<1>(edg[perm[t]]));
        
        for (auto elem: lst) {
            int tm = cmp.tm();
            
            for (auto e: elem.second)
                if (!cmp.unite(e.first, e.second)) {
                    ans[elem.first] = false;
                    break;
                }
            
            cmp.revert(tm);
        }
        
        for (int t = i0; t != i; ++t)
            cmp.unite(get<0>(edg[perm[t]]), get<1>(edg[perm[t]]));
    }

    for (char ch: ans)
        if (ch)
            cout << "YES\n";
        else
            cout << "NO\n";
    
    return 0;
}