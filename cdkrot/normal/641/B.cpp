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

const int UNKN = INT32_MAX;

// ALmost triple.
struct Triple {
    int a;
    int b;
    int c;
    int d;
};

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> field(n, vector<int>(m, UNKN));
    vector<Triple> req(q);
    for (int i = q - 1; i >= 0; --i) {
        cin >> req[i].a >> req[i].b;
        if (req[i].a == 3)
            cin >> req[i].c >> req[i].d;
    }

    for (Triple& triple: req) {
        switch (triple.a) {
        case 3:
            if (field[triple.b - 1][triple.c - 1] == UNKN)
                field[triple.b - 1][triple.c - 1] = triple.d;
            
            assert(field[triple.b - 1][triple.c - 1] == triple.d);
            break;
        case 1:
        {
            vector<int> newline(m, UNKN);
            for (int i = 0; i != m; ++i)
                newline[i] = field[triple.b - 1][(i + m - 1) % m];
            field[triple.b - 1] = std::move(newline);
        }
            break;
        case 2:
        {
            vector<int> newrow(n, UNKN);
            for (int i = 0; i != n; ++i)
                newrow[i] = field[(i + n - 1) % n][triple.b - 1];
            for (int j = 0; j != n; ++j)
                field[j][triple.b - 1] = newrow[j];
        }
            break;
        default:
            assert(false);
        }
    }

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j)
            cout << (field[i][j] == UNKN ? 0 : field[i][j]) << " ";
        cout << "\n";
    }
    
    return 0;
}