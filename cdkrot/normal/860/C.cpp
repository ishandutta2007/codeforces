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

int to_num(string a) {
    if (a[0] == '0')
        return -1;

    int res = 0;
    for (char ch: a) {
        if (ch < '0' or ch > '9')
            return -1;
        res = 10 * res + ch - '0';
    }
    return res;
}

using std::to_string;

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();
    vector<pair<string, bool>> lst(n);
    vector<char> ns(int(2e6), true);
    int num_samples = 0;
    for (int i = 0; i != n; ++i) {
        lst[i].first = input<string>();
        lst[i].second = (input<int>() == 1);

        num_samples += lst[i].second;
        

        int num = to_num(lst[i].first);
        if (num != -1)
            ns[num] = false;
    }

    string trash = "";
    for (int i = 1; true; ++i)
        if (ns[i]) {
            trash = std::to_string(i);
            break;
        }
    
    vector<string> buckets[3][2];

    vector<int> free_samples(num_samples, 0);
    vector<int> free_tests(n - num_samples, 0);
    std::iota(ALL(free_samples), 1);
    std::iota(ALL(free_tests), num_samples + 1);
    
    for (int i = 0; i != n; ++i) {
        int tid = to_num(lst[i].first);

        int A = -1;
        int B = lst[i].second == 0;
        
        if (1 <= tid and tid <= num_samples)
            A = 0;
        else if (num_samples + 1 <= tid and tid <= n)
            A = 1;
        else
            A = 2;

        if (A == 0)
            free_samples[tid - 1] = -1;
        if (A == 1)
            free_tests[tid - num_samples - 1] = -1;
        
        buckets[A][B].push_back(lst[i].first);
    }

    for (int i = 0; i != SZ(free_samples);) {
        if (free_samples[i] == -1) {
            std::swap(free_samples[i], free_samples.back());
            free_samples.pop_back();
        } else {
            ++i;
        }
    }

    for (int i = 0; i != SZ(free_tests);) {
        if (free_tests[i] == -1) {
            std::swap(free_tests[i], free_tests.back());
            free_tests.pop_back();
        } else {
            ++i;
        }
    }

    vector<pair<string, string>> log;
    
    while (SZ(buckets[0][1]) + SZ(buckets[1][0]) + SZ(buckets[2][0]) + SZ(buckets[2][1]) > 0) {
        if (SZ(free_samples) > 0) {
            string name;
            if (not buckets[1][0].empty()) {
                name = buckets[1][0].back();
                free_tests.push_back(to_num(name));
                buckets[1][0].pop_back();
            } else {
                name = buckets[2][0].back();
                buckets[2][0].pop_back();
            }

            string newname = to_string(free_samples.back());
            free_samples.pop_back();

            log.emplace_back(name, newname);
        } else if (SZ(free_tests) > 0) {
            string name;
            if (not buckets[0][1].empty()) {
                name = buckets[0][1].back();
                free_samples.push_back(to_num(name));
                buckets[0][1].pop_back();
            } else {
                name = buckets[2][1].back();
                buckets[2][1].pop_back();
            }

            string newname = to_string(free_tests.back());
            free_tests.pop_back();

            log.emplace_back(name, newname);
        } else {
            string name = buckets[0][1].back();
            free_samples.push_back(to_num(name));
            buckets[0][1].pop_back();

            log.emplace_back(name, trash);

            buckets[2][1].push_back(trash);
        }
    }

    cout << SZ(log) << "\n";
    for (auto& elem: log)
        cout << "move " << elem.first << " " << elem.second << "\n";
    
    return 0;
}