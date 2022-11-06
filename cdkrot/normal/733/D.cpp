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
#include <unordered_map>

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

struct pt {
    int crd[3];
};

namespace std {
template <>
struct hash<pair<int, int>> {
    hash<int> help;
    size_t operator()(const pair<int, int> a) const {
        return help(a.first) << 32 xor help(a.second);
    }
};
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<pt> dat(input<int>());
    for (int i = 0; i != SZ(dat); ++i)
        for (int j = 0; j != 3; ++j)
            dat[i].crd[j] = input<int>();
    
    auto func = [&dat](int diam) {
        std::map<pair<int, int>, pair<int, int>>the_map;
        for (int i = 0; i != SZ(dat); ++i) {
            if (dat[i].crd[0] >= diam and dat[i].crd[1] >= diam and dat[i].crd[2] >= diam)
                return make_pair(i, -1);
            
            for (int a = 0; a != 3; ++a)
                for (int b = 0; b != 3; ++b)
                    if (a != b and dat[i].crd[a] >= diam and dat[i].crd[b] >= diam) {
                        int c = 0 + 1 + 2 - a - b;
                        
                        if (the_map.find(make_pair(dat[i].crd[a], dat[i].crd[b])) != the_map.end()) {
                            auto val = the_map[make_pair(dat[i].crd[a], dat[i].crd[b])];
                            
                            if (val.first + dat[i].crd[c] >= diam)
                                return make_pair(val.second, i);
                        }
                    }
            for (int a = 0; a != 3; ++a)
                for (int b = 0; b != 3; ++b)
                    if (a != b and dat[i].crd[a] >= diam and dat[i].crd[b] >= diam) {
                        int c = 0 + 1 + 2 - a - b;
                        
                        if (the_map.find(make_pair(dat[i].crd[a], dat[i].crd[b])) != the_map.end()) {
                            auto& val = the_map[make_pair(dat[i].crd[a], dat[i].crd[b])];
                            val = max(val, make_pair(dat[i].crd[c], i));
                        } else {
                            the_map[make_pair(dat[i].crd[a], dat[i].crd[b])] = make_pair(dat[i].crd[c], i);
                        }
                    }
        }
        return make_pair(-1, -1);
    };
    
    int lo = 0; // def can.
    int hi = 1000 * 1000 * 1000 + 10; // no chance.

    while (hi - lo > 1) {
        int mi = lo + (hi - lo) / 2;
        if (func(mi).first != -1) // can
            lo = mi;
        else
            hi = mi;
    }

    auto ans = func(lo);
    if (ans.second == -1)
        cout << "1\n" << ans.first + 1 << "\n";
    else
        cout << "2\n" << ans.first + 1 << " " << ans.second + 1 << "\n";
    
    return 0;
}