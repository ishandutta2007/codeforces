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
#include <bitset>

using std::bitset;

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
    
    vector<bitset<1000>> requests;

    for (int k = 0; k != 10; ++k) {
        int n = (1 << k);
        
        bitset<1000> mask0, mask1;         
        for (int i = 0; i != 1000; ++i)
            if ((i % (2 * n)) < n)
                mask0[i] = 1;
            else
                mask1[i] = 1;
        requests.push_back(mask0);
        requests.push_back(mask1);
    }

    int n = input<int>();
    vector<int> answers(n, TYPEMAX(int));
    for (int i = 0; i != 20; ++i) {
        const auto& b = requests[i];
        int k = 0;
        for (int j = 0; j != n; ++j)
            k += (b[j] == 1);
        if (k > 0) {
            cout << k << "\n";
            for (int j = 0; j != n; ++j)
                if (b[j])
                    cout << j + 1 << " ";
            cout << "\n";
            cout.flush();
            
            for (int t = 0; t != n; ++t) {
                int z = input<int>();
                if (not b[t])
                    answers[t] = min(answers[t], z);
            }
        }
    }
    
    cout << "-1\n";
    for (int x: answers)
        cout << x << " ";
    cout << "\n";
    cout.flush();
    
    return 0;
}