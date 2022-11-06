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

#define int int64_t

vector<pair<int, int>> factor(int a) {
    vector<pair<int, int>> res;

    for (int i = 2; i * i <= a; ++i) {
        int cnt = 0;
        
        while (a % i == 0) {
            a /= i;
            cnt += 1;
        }

        if (cnt)
            res.emplace_back(i, cnt);
    }

    if (a != 1)
        res.emplace_back(a, 1);

    return res;
}

int mod;

vector<pair<int, int>> mod_fact;
vector<int> primes;

std::map<int, vector<int>> subfacts;

void gen_sub(int cur, int step, vector<int>& cur_fact) {
    if (step == SZ(primes)) {
        subfacts[cur] = cur_fact;
        return;
    }
    
    cur_fact.push_back(0);

    for (int i = 0; i <= mod_fact[step].second; ++i, cur *= mod_fact[step].first) {
        cur_fact.back() = i;
        gen_sub(cur, step + 1, cur_fact);
    }
    
    cur_fact.pop_back();
}

std::map<int, vector<int>> bads;
std::map<int, vector<int>> goods;

std::map<int, int> par;

int get_dp(int num) {
    static std::map<int, int> cache;

    if (cache.count(num))
        return cache.find(num)->second;

    int num_rev = SZ(goods[num]) - SZ(bads[num]);
    int best = -1;

    if (num == mod)
        best = 0;
    else {
        for (int mask = 1; mask != (1 << SZ(primes)); ++mask) {
            int nnum = num;
            
            for (int i = 0; i != SZ(primes); ++i)
                if (mask & (1 << i))
                    nnum *= primes[i];
            
            if (mod % nnum == 0) {
                int subdp = get_dp(nnum);
                if (best < subdp)
                    best = subdp, par[num] = nnum;
            }
        }
    }

    return cache[num] = best + num_rev;
}

int fastpow(int a, int n) {
    int res = 1;
    
    while (n) {
        if (n % 2)
            res = (res * a) % mod;

        n /= 2;
        a = (a * a) % mod;
    }

    return res;
}

signed main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    mod = input<int>();

    int phi = 1;
    
    mod_fact = factor(mod);
    for (auto elem: mod_fact) {
        primes.emplace_back(elem.first);
        phi *= (elem.first - 1) * fastpow(elem.first, elem.second - 1);
    }

    vector<int> cur_fact;
    gen_sub(1, 0, cur_fact);

    for (int z = 0; z != n; ++z) {
        int v = input<int>();
        bads[std::__gcd(v, mod)].push_back(v);
    }

    for (auto& pr: bads)
        std::sort(ALL(pr.second));
    
    for (int i = 0; i != mod; ++i) {
        goods[std::__gcd(i, mod)].push_back(i);
    }
    
    int nans = get_dp(1);
    cout << nans << "\n";

    vector<int> ans(nans + 1, 1);
    int num = 1;
    int ptr = 0;
    int cur = 1;
    while (true) {
        for (int targ: goods[num])
            if (not std::binary_search(ALL(bads[num]), targ)) {
                // cur -> targ
                int g = std::__gcd(cur, mod);
                int d = (fastpow(cur / g, phi - 1) * (targ / g)) % mod;
                
                ans[ptr] = (ans[ptr] * d) % mod;
                ptr += 1;
                cur = targ;
            }
        
        if (num == mod)
            break;
        ans[ptr] = (ans[ptr] * par[num] / num) % mod;
        cur      = (cur * par[num] / num) % mod;
        num      = par[num];
    }

    for (int i = 0; i != nans; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;
}