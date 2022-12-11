#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstdlib>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdlib.h>
#include <assert.h>
#include <complex>
#include <cstring>

using namespace std;

typedef long long ll;

typedef complex<double> cd;

const int inf = 1000000000;
const long long longinf = 1000000000000000000;
const double PI = 3.141592653589793;

struct Node {
    Node* go[5];
    int term;
    Node() : term(0) {
        for(int i = 0; i < 5; ++i) {
            go[i] = nullptr;
        }
    }
};

void add_string(Node* root, string& s) {
    for(int i = 0; i < s.size(); ++i) {
        if(!root->go[s[i] - 'a']) {
            root->go[s[i] - 'a'] = new Node;
        }
        root = root->go[s[i] - 'a'];
    }
    root->term++;
}

int find(Node* root, string& s) {
    vector<Node*> p(1, root), p1;
    for(int  i = 0; i < s.size(); ++i) {
        int c = s[i] - 'a';
        if(s[i] != '?') {
            for(auto cur : p) {
                if(cur->go[c])
                    p1.push_back(cur->go[c]);
            }
        } else {
            for(auto cur : p) {
                p1.push_back(cur);
                for(int j = 0; j < 5; ++j) {
                    if(cur->go[j])
                        p1.push_back(cur->go[j]);
                }
            }
        }
        p = p1;
        p1.clear();
    }
    int ans = 0;
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    for(auto cur : p)
        ans += cur->term;
    return ans;
}

void solve() {
    Node* root = new Node;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add_string(root, s);
    }
    for(int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        cout << find(root, s) << endl;
    }
}

int main() {
    cout.precision(20);
    cin.tie(0);
//    srand(time(0));
    iostream::sync_with_stdio(false);
    solve();
    return 0;
}