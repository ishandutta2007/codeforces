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

const int mod = 998244353;

int binom[4010][4010];

int fact[4010];

int get_binom(int n, int k) {
    if (k < 0 or k > n)
        return 0;
    return binom[n][k];
}

int add(int a, int b) {
    return a + b >= mod ? a + b - mod : a + b;
}

int mult(int a, int b) {
    return int64_t(a) * b % mod;
}

int shuffle_in(int elems, int groups) {
    if (groups == 0)
        return (elems == 0 ? 1 : 0);
    return get_binom(elems + groups - 1, groups - 1);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    for (int i = 0; i != 4010; ++i) {
        binom[i][0] = binom[i][i] = 1;
        
        for (int j = 1; j < i; ++j)
            binom[i][j] = add(binom[i - 1][j - 1], binom[i - 1][j]);
    }

    fact[0] = 1;
    for (int i = 1; i != 4010; ++i)
        fact[i] = mult(i, fact[i - 1]);
    
    for (int t = input<int>(); t != 0; --t) {
        int n = input<int>();

        vector<int> zeros, ones;

        int total_func = 0;
        
        for (int z = 0; z != n; ++z) {
            string num = input<string>();

            int func = 0;
            for (int i = 0; i != SZ(num); ++i) {
                int dig = num[i] - '0';
                
                if (i % 2 == 0)
                    func = (func + dig) % 11;
                else
                    func = (11 + func - dig) % 11;
            }
            
            (SZ(num) % 2 == 0 ? zeros : ones).pb((2 * func) % 11);
            total_func += func;
        }

        total_func %= 11;
        total_func = (11 - total_func) % 11;
        
        int num_plus_zeros_gr = (SZ(ones) + 1 + 1) / 2;
        int num_minus_zeros_gr = (SZ(ones) + 1) / 2;

        int num_plus_ones = (SZ(ones) + 1) / 2;
        int num_minus_ones = (SZ(ones)) / 2;

        auto calc_dp = [](const vector<int>& elems) {
            vector<vector<int>> cur(11, vector<int>(SZ(elems) + 1, 0));
            cur[0][0] = 1;
            
            for (int val: elems) {
                vector<vector<int>> nw(11, vector<int>(SZ(elems) + 1, 0));
                
                for (int i = 0; i != 11; ++i)
                    for (int j = 0; j <= SZ(elems); ++j) {
                        nw[i][j] = cur[i][j];
                        if (j != 0)
                            nw[i][j] = add(nw[i][j], cur[(11 + i - val) % 11][j - 1]);
                    }

                cur = std::move(nw);
            }

            return cur;
        };
        
        auto dp_zero = calc_dp(zeros);
        auto dp_ones = calc_dp(ones);
        
        int ans = 0;
        for (int num_plus_zeros = 0; num_plus_zeros <= SZ(zeros); ++num_plus_zeros) {
            int num_minus_zeros = SZ(zeros) - num_plus_zeros;

            int multipl = mult(fact[num_plus_zeros], fact[num_minus_zeros]);
            multipl = mult(multipl, mult(fact[num_minus_ones], fact[num_plus_ones]));
            multipl = mult(multipl, mult(shuffle_in(num_plus_zeros, num_plus_zeros_gr), shuffle_in(num_minus_zeros, num_minus_zeros_gr)));

            int ans_base = 0;
            for (int s0 = 0; s0 != 11; ++s0)
                for (int s1 = 0; s1 != 11; ++s1)
                    if ((total_func + s0 + s1) % 11 == 0)
                        ans_base = add(ans_base, mult(dp_ones[s1][num_plus_ones], dp_zero[s0][num_plus_zeros]));
            ans = add(ans, mult(multipl, ans_base));
        }

        cout << ans << "\n";
    }
    
    return 0;
}