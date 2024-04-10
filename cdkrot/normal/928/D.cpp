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

struct node {
    node() {
        std::fill(go, go + 26, (node*)NULL);
    }

    int cnt = 0;
    bool term = false;
    node* go[26];
};

int main() {
    // code here.
    string text;

    string buf;
    while (std::getline(cin, buf))
        text += buf + "\n";

    vector<string> tokens;
    for (int i = 0; text[i] != 0;) {
        // if (text[i] == '\r') {
        //     ++i;
        //     continue;
        // }
        
        if (not std::isalpha(text[i]))
            tokens.push_back(string(1, text[i])), ++i;
        else {
            string res;

            while (text[i] != 0 and std::isalpha(text[i]))
                res += text[i], ++i;

            tokens.push_back(res);
        }
    }

    node* root = new node();
    int ans = 0;

    set<string> added;
    
    for (string tok: tokens) {
        if (SZ(tok) == 1 and not std::isalpha(tok[0])) {
            ans += 1;
            continue;
        }

        auto score = [&]() {
            node* cur = root;
            int i = 0;

            while (i != SZ(tok) and (i == 0 or cur->cnt > 1)) {
                if (cur->go[tok[i] - 'a'] == NULL) {
                    ans += SZ(tok);
                    return;
                }
                
                cur = cur->go[tok[i++] - 'a'];
            }

            int i0 = i;
            while (i != SZ(tok) and cur->term == false) {
                if (cur->go[tok[i] - 'a'] == NULL) {
                    ans += SZ(tok);
                    return;
                }

                cur = cur->go[tok[i++] - 'a'];
            }

            if (i0 + 1 + SZ(tok) - i < SZ(tok) and cur->term)
                ans += i0 + 1 + SZ(tok) - i;
            else
                ans += SZ(tok);
        };

        auto update = [&]() {
            node* cur = root;
            cur->cnt += 1;
            for (char ch: tok) {
                if (cur->go[ch - 'a'] == NULL)
                    cur->go[ch - 'a'] = new node();
                
                cur = cur->go[ch - 'a'];
                cur->cnt += 1;
            }
        
            cur->term = true;
        };
        
        score();
        if (not added.count(tok)) {
            added.insert(tok);
            update();
        }
    }

    cout << ans << "\n";
    
    return 0;
}