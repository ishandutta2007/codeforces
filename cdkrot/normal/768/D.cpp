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

const int mdays = (int)1e4;
const int msph = (int)1e3 + 228;

long double dp[mdays][msph];

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int k, q;
    cin >> k >> q;

    dp[0][0] = 1;
    
    for (int day = 0; day != mdays - 1; ++day) {
        for (int count = 0; count <= k; ++count) {
            dp[day + 1][count] += ((long double)count / k) * dp[day][count];
            dp[day + 1][count + 1] += ((long double)(k - count) / k) * dp[day][count];
        }
    }

    vector<long double> supercache(mdays);
    for (int i = 0; i != mdays; ++i)
        supercache[i] = dp[i][k];
    
    vector<int> req(q);
    input_seq(ALL(req));
    
    vector<int> perm(q);
    for (int i = 0; i != q; ++i)
        perm[i] = i;

    std::sort(ALL(perm), [&req](int a, int b) {return req[a] < req[b];});

    vector<int> ans(q, -1);
    
    int cur_pos = 0;
    for (int p: perm) {
        while (supercache[cur_pos] < 1.0 * req[p] / 2000)
            ++cur_pos;
        ans[p] = cur_pos;
    }

    for (int i = 0; i != q; ++i)
        cout << ans[i] << "\n";
    
    return 0;
}