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

bool update(string& src, const string& nw) {
    if (src == "" or src.size() > nw.size() or (src.size() == nw.size() and src > nw)) {
        src = nw;
        return true;
    }
    return false;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.

    vector<string> E(256); // no 'E'.
    vector<string> T(256); // no 'T'.
    vector<string> F(256); // almost no 'T'.

    F[0b00110011] = "y";
    F[0b00001111] = "x";
    F[0b01010101] = "z";

    while (true) {
//        cout << "working.." << std::endl;
        
        bool modif = false;

        // F from F.
        for (int i = 0; i != 256; ++i)
            if (F[i] != "")
                modif or_eq update(F[i ^ 0b11111111], "!" + F[i]);

        // F from E.
        for (int i = 0; i != 256; ++i)
            if (E[i] != "")
                modif or_eq update(F[i], "(" + E[i] + ")");

        // T from F.
        for (int i = 0; i != 256; ++i)
            if (F[i] != "")
                modif or_eq update(T[i], F[i]);

        // T from T & F.
        int iter = 0;
        while (true) {
            iter += 1;
            bool local = false;
            for (int i = 0; i != 256; ++i)
                for (int j = 0; j != 256; ++j)
                    if (T[i] != "" and F[j] != "")
                        local or_eq update(T[i & j], T[i] + "&" + F[j]);

            if (not local)
                break;
        }

        // E from T.
        for (int i = 0; i != 256; ++i)
            if (T[i] != "")
                modif or_eq update(E[i], T[i]);

        // E from E | T.
        while (true) {
            iter += 1;
            bool local = false;
            for (int i = 0; i != 256; ++i)
                for (int j = 0; j != 256; ++j)
                    if (E[i] != "" and T[j] != "")
                        local or_eq update(E[i | j], E[i] + "|" + T[j]);

            if (not local)
                break;
        }

        if (iter > 2)
            modif = true;
        
        if (not modif)
            break;
    }

//    for (int i = 0; i != 256; ++i)
//        cout << E[i] << std::endl;

    for (int n = input<int>(); n != 0; --n) {
        string s = input<string>();
        int mask = 0;
        for (int i = 0; i != 8; ++i)
            mask |= ((s[i] - '0') << (7 - i));

        cout << E[mask] << "\n";
    }
    
    return 0;
}