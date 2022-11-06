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

const int maxn = 1.1e5;
const int maxk = 22;

int64_t dp[maxk][maxn];
int the_n;
int the_k;

int seq[maxn];
int ind[maxn];

struct mo_t {
    int cur_l;
    int cur_r;

    int counts[maxn];
    int64_t sum;

    void inc_r() {
        ++cur_r;
        sum -= counts[seq[cur_r]] * 1ll * (counts[seq[cur_r]] - 1) ;
        counts[seq[cur_r]] += 1;
        sum += counts[seq[cur_r]] * 1ll * (counts[seq[cur_r]] - 1) ;
    }

    void dec_l() {
        --cur_l;
        sum -= counts[seq[cur_l]] * 1ll * (counts[seq[cur_l]] - 1) ;
        counts[seq[cur_l]] += 1;
        sum += counts[seq[cur_l]] * 1ll * (counts[seq[cur_l]] - 1) ;
    }

    void dec_r() {
        sum -= counts[seq[cur_r]] * 1ll * (counts[seq[cur_r]] - 1) ;
        counts[seq[cur_r]] -= 1;
        sum += counts[seq[cur_r]] * 1ll * (counts[seq[cur_r]] - 1) ;

        --cur_r;
    }

    void inc_l() {
        sum -= counts[seq[cur_l]] * 1ll * (counts[seq[cur_l]] - 1) ;
        counts[seq[cur_l]] -= 1;
        sum += counts[seq[cur_l]] * 1ll * (counts[seq[cur_l]] - 1) ;

        ++cur_l;
    }

    void resize(int new_l, int new_r) {
        while (cur_r < new_r)
            inc_r();
        
        while (new_l < cur_l)
            dec_l();

        while (cur_r > new_r)
            dec_r();

        while (new_l > cur_l)
            inc_l();
    }
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    the_n = input<int>();
    the_k = input<int>();

    std::map<int, int> cind;
    
    for (int i = 0; i != the_n; ++i) {
        seq[i] = input<int>();
        ind[i] = cind[seq[i]];

        cind[seq[i]] += 1;
    }

    // calculate dp_0.
    dp[0][0] = 0;
    for (int i = 1; i != the_n; ++i)
        dp[0][i] = dp[0][i - 1] + 2 * ind[i];

    for (int t = 1; t != the_k; ++t) {
        using std::tuple;
        using std::get;
        
        vector<tuple<int, int, int, int>> requests = {{0, the_n - 1, 0, the_n - 1}};

        while (not requests.empty()) {
            vector<tuple<int, int, int, int>> newrequests;

            mo_t mo;
            memset(&mo, 0, sizeof(mo_t));
            mo.cur_l = mo.cur_r = 0;
            mo.counts[seq[0]] += 1;
            mo.sum += 0;

            for (auto req: requests) {
                int l = get<0>(req);
                int r = get<1>(req);
                int L = get<2>(req);
                int R = get<3>(req);

                if (l > r)
                    continue;
                
                int m = (l + r) / 2;                
                mo.resize(L, m);

                int64_t best = (L == 0 ? 0 : dp[t - 1][L - 1]) + mo.sum;
                int pbest = L;
                
                for (int i = L + 1; i <= R and i <= m; ++i) {
                    mo.inc_l();
                    
                    if (best > dp[t - 1][i - 1] + mo.sum) {
                        best  = dp[t - 1][i - 1] + mo.sum;
                        pbest = i;
                    }
                }

                dp[t][m] = best;
                newrequests.emplace_back(l, m - 1, L, pbest);
                newrequests.emplace_back(m + 1, r, pbest, R);
            }

            requests = std::move(newrequests);
        }
    }

    cout << dp[the_k - 1][the_n - 1] / 2 << "\n";
    
    return 0;
}