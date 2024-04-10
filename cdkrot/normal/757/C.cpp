// Copyright (C) 2016 Sayutin Dmitry.
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

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<int> types(input<int>(), 0);
    int tid = 1;
    
    for (int i = 0; i != n; ++i) {
        vector<int> all(input<int>());
        for (int& x: all)
            x = input<int>() - 1;
        std::sort(ALL(all));

        vector<pair<int, int>> out; // (pokemon, count)
        for (int x: all)
            if (out.empty() or out.back().first != x)
                out.emplace_back(x, 1);
            else
                out.back().second += 1;

        std::sort(ALL(out), [](pair<int, int> a, pair<int, int> b){return a.second < b.second;});
        for (int ptr = 0; ptr != SZ(out);) {
            int next;
            for (next = ptr; next != SZ(out) and out[next].second == out[ptr].second; ++next) {}

            // [ptr, next).
            vector<int> has;
            for (int i = ptr; i != next; ++i)
                has.push_back(out[i].first);

            std::sort(ALL(has), [&types](int a, int b){return types[a] < types[b];});

            for (int newptr = 0; newptr != SZ(has);) {
                int newnext;
                for (newnext = newptr; newnext != SZ(has) and types[has[newnext]] == types[has[newptr]]; ++newnext) {}

                for (; newptr != newnext; ++newptr)
                    types[has[newptr]] = tid;

                ++tid;
            }
            
            ptr = next;
        }
    }

    const int mod = 1000 * 1000 * 1000 + 7;
    
    vector<int> factorials(SZ(types) + 1, 1);
    for (int i = 2; i < SZ(factorials); ++i)
        factorials[i] = factorials[i - 1] * int64_t(i) % mod;

    std::sort(ALL(types));
    int ans = 1;
    for (int ptr = 0; ptr != SZ(types);) {
        int next;
        for (next = ptr; next != SZ(types) and types[next] == types[ptr]; ++next) {}

        ans = ans * int64_t(factorials[next - ptr]) % mod;
        
        ptr = next;
    }

    cout << ans << "\n";
    
    return 0;
}