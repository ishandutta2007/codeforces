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

void dfs(const vector<uint32_t>& perm, vector<char>& used, uint32_t v, vector<uint32_t>& out) {
    out.push_back(v);
    used[v] = true;

    if (not used[perm[v]])
        dfs(perm, used, perm[v], out);
}

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<uint32_t> perm(input<uint32_t>());
    for (uint32_t& v: perm)
        v = input<uint32_t>() - 1;

    vector<vector<uint32_t>> lists;
    vector<char> used(perm.size(), false);

    vector<vector<uint32_t>> by_cnt(perm.size() + 1);
    
    for (uint32_t i = 0; i != perm.size(); ++i)
        if (not used[i]) {
            lists.resize(lists.size() + 1);
            dfs(perm, used, i, lists.back());
            by_cnt[lists.back().size()].push_back(lists.size() - 1);
        }

    for (uint32_t i = 0; i != by_cnt.size(); ++i) {
        if (i % 2 == 0 and by_cnt[i].size() % 2 == 1) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<uint32_t> restored(perm.size(), 0xdeadbeef);
    for (uint32_t i = 0; i != by_cnt.size(); ++i) {
        if (i % 2 == 0)
            for (uint32_t j = 0; j != by_cnt[i].size(); j += 2) {
                vector<uint32_t>& list1 = lists[by_cnt[i][j]];
                vector<uint32_t>& list2 = lists[by_cnt[i][j + 1]];
                vector<uint32_t> merged;
                for (uint32_t k = 0; k != list1.size(); ++k)
                    merged.push_back(list1[k]), merged.push_back(list2[k]);
                for (uint32_t k = 0; k != merged.size(); ++k)
                    restored[merged[k]] = merged[(k + 1) % merged.size()];
            }
        else
            for (uint32_t j: by_cnt[i]) {
                vector<uint32_t> list = lists[j];
                vector<uint32_t> merged(list.size(), 0xdeadbeef);

                uint32_t pos = 0;
                for (uint32_t v: list) {
                    merged[pos] = v;
                    pos = (pos + 2) % merged.size();
                }

                for (uint32_t k = 0; k != merged.size(); ++k)
                    restored[merged[k]] = merged[(k + 1) % merged.size()];
            }
    }

    
    for (uint32_t v: restored)
        cout << v + 1 << " ";
    cout << "\n";
    return 0;
}