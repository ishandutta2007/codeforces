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

struct node {
    node(int uid, int ln) {
        for (int t = 0; t != 26; ++t)
            go[t] = NULL;
        
        suf = NULL;
        id = uid;
        len = ln;
    }

    int id;
    int len;
    node* suf;
    node* go[26];
};

pair<int, int> dfs(vector<vector<int>>& graph, int v) {
    // without us, with us
    pair<int, int> res = {0, 1};
    for (auto u: graph[v]) {
        auto r = dfs(graph, u);
        
        res.first += max(r.first, r.second);
        res.second += r.first;
    }
    return res;
}
    
int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // code here.
    for (int t = input<int>(); t != 0; --t) {
        int n = input<int>();
        int cur_id = 1;
        node* root = new node(0, 0);

        for (int i = 0; i != n; ++i) {
            string s = input<string>();
            node* cur = root;

            for (char ch: s) {
                if (cur->go[ch - 'a'] == NULL)
                    cur->go[ch - 'a'] = new node(cur_id++, cur->len + 1);

                cur = cur->go[ch - 'a'];
            }
        }

        std::queue<node*> q;
        root->suf = root;

        for (int i = 0; i != 26; ++i)
            if (root->go[i] == NULL)
                root->go[i] = root;
            else {
                root->go[i]->suf = root;
                q.push(root->go[i]);
            }

        vector<vector<int>> graph(cur_id);
        vector<char> is_root(cur_id, 1);
        // precondition: nodes in q have filled suf & go.
        
        while (not q.empty()) {
            node* v = q.front();
            q.pop();

            for (int i = 0; i != 26; ++i)
                if (v->go[i] == NULL)
                    v->go[i] = v->suf->go[i];
                else {
                    v->go[i]->suf = v->suf->go[i];
                    q.push(v->go[i]);

                    node* client = v->go[i];
                    if (client->suf->len == client->len - 1) {
                        graph[client->suf->id].pb(client->id);
                        is_root[client->id] = false;
                    }
                }
        }

        int ans = 0;
        for (int i = 1; i != cur_id; ++i)
            if (is_root[i]) {
                auto r = dfs(graph, i);
                ans += max(r.first, r.second);
            }
        cout << ans << "\n";
    }
    
    return 0;
}