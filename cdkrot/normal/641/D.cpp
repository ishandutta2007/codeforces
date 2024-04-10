// Copyright (C) 2016 "Time to emerge -e that world".
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

template <typename T>
T input() {
    T res;
    cin >> res;
    return res;
}

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

#define FloatT double

FloatT zero = -1e-9;
FloatT one  = 1 + 1e-9;

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n = input<int>();
    vector<FloatT> maxs(n), mins(n);

    std::generate(maxs.begin(), maxs.end(), input<FloatT>);
    std::generate(mins.begin(), mins.end(), input<FloatT>);

    vector<FloatT> P(n, FloatT(-1.0));
    vector<FloatT> Q(n, FloatT(-1.0));
    FloatT p_sum = 0.0;
    FloatT q_sum = 0.0;

    for (int i = n - 1; i >= 0; --i) {
        FloatT S = mins[i] + maxs[i];
        FloatT b = q_sum - p_sum - S;
        FloatT c = -S * q_sum + mins[i];

        
        FloatT Discr = b * b - 4 * c;
        Discr = max(Discr, 1e-16);
        FloatT x1 = (-b + std::sqrt(Discr)) / 2.0;
        FloatT x2 = (-b - std::sqrt(Discr)) / 2.0;

        bool b1 = (zero <= x1 and x1 <= S + 1e-9);
        bool b2 = (zero <= x2 and x2 <= S + 1e-9);
        
        assert(b1 or b2);

        Q[i] = (b1 ? x1 : x2);
        P[i] = S - Q[i];
        p_sum += P[i];
        q_sum += Q[i];
    }

    cout.precision(10);
    cout << std::fixed;
    
    for (int i = 0; i != n; ++i)
        cout << P[i] << " ";
    cout << "\n";
    for (int i = 0; i != n; ++i)
        cout << Q[i] << " ";
    cout << "\n";

    
    return 0;
}