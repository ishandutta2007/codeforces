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

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<int> a(n), b(n);

    if (n == 1) {
        cout << "1\n1\n";
        return 0;
    }
    
    for (int& e: a)
        e = input<int>();
    for (int& e: b)
        e = input<int>();

    vector<int> sel1, sel2;
    int64_t s1  = 0, s2  = 0;
    int64_t s1a = 0, s2a = 0;
    
    vector<int> ordb(n);
    iota(ordb.begin(), ordb.end(), 0);
    std::sort(ALL(ordb), [&b](int i, int j) {return b[i] > b[j];});

    for (int i = 0; i != n; ++i) {
        int id = ordb[i];
        
        if (i % 2 == 0) {
            s1  += b[id];
            s1a += a[id];
            sel1.push_back(id);
        } else {
            s2  += b[id];
            s2a += a[id];
            sel2.push_back(id);
        }
    }

    auto output = [](const vector<int>& ans) {
        cout << ans.size() << "\n";
        for (int e: ans)
            cout << e + 1 << " ";
        cout << "\n";
    };
    
    if (s1a > s2a) {
        if (s1 == s2)
            sel1.push_back(sel2[0]);
        output(sel1);
    } else if (s2a > s1a) {
        sel2.push_back(sel1[0]);

        output(sel2);
    } else if (s1a == s2a) {
        if (s1 > s2) {
            sel2.push_back(sel1[0]);
            output(sel2);
        } else {
            // s1 == s2
            sel2.push_back(sel1[0]);
            output(sel2);
        }
    }
    
    return 0;
}