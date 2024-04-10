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

bool eat(vector<int>& buf, int base, vector<pair<int, char>>& pans) {
    int mx = *std::max_element(ALL(buf));

    int pos = -1;
    for (int i = 0; i != SZ(buf); ++i)
        if (buf[i] == mx)
            if ((i != 0 and buf[i - 1] < mx) or (i + 1 != SZ(buf) and buf[i + 1] < mx))
                    pos = i;
    if (pos == -1)
        return false;
    while (buf.size() != 1) {
        if (pos + 1 != SZ(buf) and buf[pos + 1] < buf[pos]) {
            buf[pos] += buf[pos + 1];
            buf.erase(buf.begin() + pos + 1);
            pans.emplace_back(base + pos, 'R');
        } else {
            buf[pos] += buf[pos - 1];
            buf.erase(buf.begin() + pos - 1);
            pans.emplace_back(base + pos, 'L');
            pos -= 1;
        }
    }
    return true;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> start(input<int>());
    generate(ALL(start), input<int>);
    
    vector<int> end(input<int>());
    generate(ALL(end), input<int>);
    
    vector<pair<int, char>> the_ans;

    int cur_start = 0;
    for (int i = 0; i != SZ(end); ++i) {
        int the_start = cur_start;
        int cur_sum = 0;
        while (cur_start != SZ(start) and cur_sum < end[i])
            cur_sum += start[cur_start++];

        if (cur_sum != end[i]) {
            cout << "NO\n";
            return 0;
        }

        if (cur_start - the_start > 1) {
            vector<int> buf(cur_start - the_start);
            std::copy(start.begin() + the_start, start.begin() + cur_start, buf.begin());
            
            if (not eat(buf, i + 1, the_ans)) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    if (cur_start != SZ(start))
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (auto elem: the_ans)
            cout << elem.first << " " << elem.second << "\n";
    }
    
    return 0;
}