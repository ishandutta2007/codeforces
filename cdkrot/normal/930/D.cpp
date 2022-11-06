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

#define x first
#define y second

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<pair<int, int>> a(n);

    for (int i = 0; i != n; ++i)
        cin >> a[i].first >> a[i].second;

    int64_t ans = 0;
    for (int rem = 0; rem <= 1; ++rem) { // searching for white with (x + y) % 2 == 1 - rem.
        vector<pair<int, int>> b;
        
        for (auto val: a)
            if (((val.first + val.second) & 1) == rem)
                b.push_back(val);

        if (rem)
            for (auto& elem: b)
                elem.second -= 1;

        // (elem.first + elem.second) % 2 == 0.
        for (auto& elem: b) {
            pair<int, int> newelem = make_pair((elem.first + elem.second) / 2, (elem.first - elem.second) / 2);
            elem = newelem;
        }

        std::sort(ALL(b));
        if (not b.empty()) {
            int tmp = b[0].first;

            for (auto& elem: b)
                elem.first -= tmp;

            vector<pair<int, int>> responce1(b.back().first + 1), responce2(b.back().first + 1);
            
            {
                int p_b = 0;

                int L = 1e9, R = -1e9;
                for (int i = 0; i <= b.back().first; ++i) {
                    while (p_b != SZ(b) and b[p_b].first == i) {
                        L = min(L, b[p_b].second);
                        R = max(R, b[p_b].second);

                        ++p_b;
                    }

                    responce1[i] = {L, R};
                }
            }

            {
                int p_b = SZ(b) - 1;

                int L = 1e9, R = -1e9;
                for (int i = b.back().first; i >= 0; --i) {
                    while (p_b != -1 and b[p_b].first == i) {
                        L = min(L, b[p_b].second);
                        R = max(R, b[p_b].second);

                        --p_b;
                    }

                    responce2[b.back().first - i] = {L, R};
                }            
            }

            // for (auto elem: responce1)
            //     fprintf(stderr, "( %d , %d )\n", elem.first, elem.second);
            // fprintf(stderr, "\n");                    
            // for (auto elem: responce2)
            //     fprintf(stderr, "( %d , %d )\n", elem.first, elem.second);
            
            for (int i = 0; i != SZ(responce1) - 1; ++i) {
                int j = SZ(responce1) - 2 - i;

                int cL = max(responce1[i].first, responce2[j].first);
                int cR = min(responce1[i].second, responce2[j].second);

                if (cL < cR)
                    ans += cR - cL;
            }
        }

        // cerr << ans << std::endl;
    }

    cout << ans << "\n";
    
    return 0;
}