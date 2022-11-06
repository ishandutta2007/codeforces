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

using std::sort;
using std::generate;
using std::min_element;
using std::max_element;

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

struct vec {
    double x;
    double y;
};

vec normalize(vec a) {
    double len = std::sqrt(a.x * a.x + a.y * a.y);
    return vec {a.x / len, a.y / len};
}

vec operator+(vec a, vec b) {
    return vec {a.x + b.x, a.y + b.y};
}
vec operator*(vec a, double f) {
    return vec {a.x * f, a.y * f};
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

std::ostream& operator<<(std::ostream& os, vec v) {
    os << v.x << " " << v.y << "\n";
    return os;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    double px, py, vx, vy, a, b, c, d;
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;

    vec dir = normalize(vec {vx, vy});
    vec cdir = {dir.y, -dir.x};
    if (cross(dir, cdir) < 0)
        cdir = cdir * (-1.0);
    
    vec p0 = vec {px, py};
    
    vec p1 = p0 + dir * b;
    vec p2 = p0 + cdir * (a / 2);
    vec p3 = p0 + cdir * (c / 2);

    vec p4 = p3 + dir * (-d);
    vec p5 = p4 + cdir * (-c);
    
    vec p6 = p0 + cdir * (-c / 2);
    vec p7 = p0 + cdir * (-a / 2);

    cout << std::fixed;
    cout.precision(10);
    cout << p1 << p2 << p3 << p4 << p5 << p6 << p7;
    return 0;
}