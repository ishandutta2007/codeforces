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
#include <numeric>

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

int subtree_sz[(int)1e6];
int decomp[(int)1e6];

int calc_dp(const vector<vector<int>>& tree, int v, int p) {
    if (decomp[v] != 0)
        return 0;
    subtree_sz[v] = 1;
    for (int u: tree[v])
        if (u != p)
            subtree_sz[v] += calc_dp(tree, u, v);
    return subtree_sz[v];
}

void do_decomp(const vector<vector<int>>& tree, int v, int dep) {
    calc_dp(tree, v, -1);
    int root = v, par = -1;
    
    while (true) {
        int togo = -1;
        for (int u: tree[root])
            if (decomp[u] == 0 and u != par and 2 * subtree_sz[u] >= subtree_sz[v]) {
                togo = u;
                break;
            }

        if (togo == -1)
            break;
        par = root;
        root = togo;
    }

    decomp[root] = dep;
    
    for (int u: tree[root])
        if (decomp[u] == 0)
            do_decomp(tree, u, dep + 1);
}

void do_search(const vector<vector<int>>& graph, vector<char>& used, vector<vector<int>>& lists, vector<int>& stack) {
    pair<int, int> NEVER = {stack[1], stack[0]};
    
    while (stack.size() >= 2) {
        int u = stack[stack.size() - 2];
        int v = stack[stack.size() - 1];
        int n = graph.size();
        
        auto sort_cw = [v, n](int j, int k) {
            j -= v;
            k -= v;
            if (j < 0)
                j += n;
            if (k < 0)
                k += n;

            return j > k;
        };

        auto it = std::upper_bound(ALL(graph[v]), u, sort_cw);
        if (it == graph[v].end()) {
            stack.pop_back();
            continue;
        }

        int w = *it;
        if (not used[w])
            stack.push_back(w), used[w] = 1;
        else {
            int GID = SZ(lists);
            lists.push_back(vector<int> {w});
            while (stack.back() != w) {
                if (make_pair(stack[stack.size() - 1], stack[stack.size() - 2]) != NEVER) {
                    vector<int> new_stack = {stack[stack.size() - 1], stack[stack.size() - 2]};
                    do_search(graph, used, lists, new_stack);
                }
                
                lists[GID].push_back(stack.back());
                stack.pop_back();
            }
            
            stack.push_back(v);
            assert(stack.size() == 2);
            NEVER = {stack[1], stack[0]};
        }
    }
}

/*
void dfs(const vector<vector<int>>& graph, vector<char>& used, vector<vector<int>>& lists, int v, int p) {
    stack.push_back(v);
    used[v] = 1;
    for (int u: graph[v])
        if (u != p) {
            if (used[u]) {
                lists.push_back(vector<int> {v});
                for (int i = SZ(stack) - 2; i >= 0 and stack[i] != v; --i)
                    lists.back().push_back(stack[i]);
            } else {
                dfs(graph, used, lists, u, v);
            }
        }
    
    stack.pop_back();
}
*/

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    int n = input<int>();

    vector<vector<int>> graph(n);

    int m = input<int>();
    
    for (int i = 0; i != m; ++i) {
        int v = input<int>() - 1;
        int u = input<int>() - 1;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i != n; ++i) {
        graph[i].push_back((i + 1) % n);
        graph[(i + 1) % n].push_back(i);
    }

    for (int i = 0; i != n; ++i) {
        auto sort_cw = [i, n](int j, int k) {
            j -= i;
            k -= i;
            if (j < 0)
                j += n;
            if (k < 0)
                k += n;

            return j > k;
        };
        std::sort(ALL(graph[i]), sort_cw);
    }
    
    vector<vector<int>> lists;
    vector<char> used(n, false);
    vector<int> stack = {0, 1};
    used[0] = used[1] = 1;
    do_search(graph, used, lists, stack);

    std::map<pair<int, int>, pair<int, int>> mp;
    for (int i = 0; i != SZ(lists); ++i) {
        for (int j = 0; j != SZ(lists[i]); ++j) {
            int nxt = (j + 1) % SZ(lists[i]);

            int a = lists[i][j];
            int b = lists[i][nxt];

            if (not (a <= b))
                std::swap(a, b);
            
            if (b - a != 1 and not (a == 0 and b == n - 1)) {
                auto pr = make_pair(a, b);
                if (mp.find(pr) == mp.end())
                    mp[pr] = {i, -1};
                else
                    mp[pr].second = i; 
            }
        }
    }

    vector<vector<int>> tree(SZ(lists));
    for (auto elems: mp) {
        tree[elems.second.first].push_back(elems.second.second);
        tree[elems.second.second].push_back(elems.second.first);
    }

//    std::fill(decomp, decomp + SZ(tree), -1);
    do_decomp(tree, 0, 1);
    
    for (int i = 0; i != SZ(lists); ++i)
        std::sort(lists[i].rbegin(), lists[i].rend());

    vector<int> perm(SZ(lists));
    std::iota(ALL(perm), 0);

    std::sort(ALL(perm), [&lists](int i, int j) {
            return lists[i] < lists[j];
        });
    
/*    vector<int> the_ans(SZ(lists));
    for (int i = 0; i != SZ(lists); ++i)
        the_ans[perm[i]] = decomp[i];
*/
    for (int i = 0; i != SZ(lists); ++i)
        cout << decomp[perm[i]] << " ";
    cout << "\n";
    
    return 0;
}