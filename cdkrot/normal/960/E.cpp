// Copyright (C) 2018 Sayutin Dmitry.
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

const int mod = 1000 * 1000 * 1000 + 7;

int add(int a, int b) {
    return (a + b >= mod ? a + b - mod : a + b);
}

int sub(int a, int b) {
    return (a >= b ? a - b : mod + a - b);
}

int mult(int a, int b) {
    return (int64_t(a) * b) % mod;
}

using std::tuple;
using std::make_tuple;
using std::get;

void combine(tuple<int, int, int, int> r1,
             tuple<int, int, int, int> r2, int& ans) {

//    cout << ans << "#\n";

    int dans = 0;
    dans = sub(mult(get<0>(r1), get<3>(r2)), mult(get<2>(r1), get<1>(r2)));
    dans = add(dans, sub(mult(get<0>(r2), get<3>(r1)), mult(get<2>(r2), get<1>(r1))));

    ans = add(ans, mult(2, dans));
                  

    
//    cout << ans << "#\n";
}

void extend(tuple<int, int, int, int>& r, int v) {
    std::swap(get<0>(r), get<2>(r));
    std::swap(get<1>(r), get<3>(r));

    get<1>(r) = sub(0, get<1>(r));
    get<3>(r) = sub(0, get<3>(r));

    get<1>(r) = add(get<1>(r), mult(v, get<0>(r)));
    get<3>(r) = add(get<3>(r), mult(v, get<2>(r)));
}

void merge_in(tuple<int, int, int, int>& r1, tuple<int, int, int, int> r2) {
    get<0>(r1) = add(get<0>(r1), get<0>(r2));
    get<1>(r1) = add(get<1>(r1), get<1>(r2));
    get<2>(r1) = add(get<2>(r1), get<2>(r2));
    get<3>(r1) = add(get<3>(r1), get<3>(r2));
}


tuple<int, int, int, int> zhfs(vector<vector<int>>& graph, vector<int>& vals, int v, int p, int& ans) {
    ans = add(ans, sub(add(0,vals[v]), 0));
    
    tuple<int, int, int, int> r1 = make_tuple(0, 0, 1, sub(add(0,vals[v]), 0));

    for (int u: graph[v])
        if (u != p) {
            auto r2 = zhfs(graph, vals, u, v, ans);

            combine(r1, r2, ans);

            extend(r2, sub(add(0,vals[v]), 0));
            merge_in(r1, r2);
        }

//    cerr << "!" << v << " " << get<0>(r1) << " " << get<1>(r1) << " " << get<2>(r1) << " " << get<3>(r1) << "\n";
    
    return r1;
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<int> vals(n);
    input_seq(ALL(vals));

    vector<vector<int>> graph(n);
    for (int i = 1; i != n; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    
    int ans = 0;
    
    zhfs(graph, vals, 0, -1, ans);
    cout << ans << "\n";
    
    return 0;
}