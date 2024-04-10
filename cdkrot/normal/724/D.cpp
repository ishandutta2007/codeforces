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
    int m = input<int>();
    string s = input<string>();

    std::set<int> positions;
    for (int i = 0; i <= SZ(s) - m; ++i)
        positions.insert(i);
    
    string ans = "";
    for (char ch = 'a'; ch <= 'z' and not positions.empty(); ++ch) {
        vector<int> lst;
        for (int i = 0; i != SZ(s); ++i)
            if (s[i] == ch)
                lst.push_back(i);

        if (lst.size() != 0) {
            vector<pair<int, int>> selected;

            for (int i = 0; i != SZ(lst); ++i) {
                int v = lst[i];
                int LO = max(0, v - m + 1);
                int HI = min(v, SZ(s) - m);
                
                if (positions.lower_bound(LO) != positions.upper_bound(HI)) {
                    LO = *positions.lower_bound(LO);
                    HI = *std::prev(positions.upper_bound(HI));

                    if (selected.size() >= 1) {
                        if (LO <= selected.back().first) // last one is wasted.
                            selected.pop_back();
                    }

                    
                    if (selected.size() >= 1) {
                        auto it = positions.lower_bound(selected.back().second + 1);
                        if (it == positions.end())
                            LO = 9999 * 100500;
                        else
                            LO = max(LO, *it);
                    }
                    
                    if (LO <= HI)
                        selected.emplace_back(LO, HI);
                }
            }

            for (auto elem: selected)
                positions.erase(positions.lower_bound(elem.first), positions.upper_bound(elem.second));

            for (size_t i = 0; i != (positions.empty() ? selected.size() : lst.size()); ++i)
                ans += ch;
            /*
            int REQR = v.size() - m;

            int MX = 0;
            int MX_NEXT = -1;
            int ANS = 0;
            
            for (int i = 0; i != segments.size(); ++i) {
                if (MX < segments[i].first)
                    MX = MX_NEXT, MX_NEXT = -1, ANS += 1;
                
                if (segments[i].first <= MX)
                    MX_NEXT = max(MX_NEXT, segments[i].second + 1);
                else {
                    ANS = -3;
                    break;
                }
            }

            if (MX_NEXT != -1)
                MX = MX_NEXT, MX_NEXT = -1, ANS += 1;
            
            if (MX != REQR or ANS < 0)
                2
            */
        }
    }
    cout << ans << "\n";
    return 0;
}