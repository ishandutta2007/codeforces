#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 333, inf = 1011111111;

int n, v[max_n];
string s;
vector<int> q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        ++v[s[i]];
    }
    q.push_back('A');
    q.push_back('C');
    q.push_back('G');
    q.push_back('T');
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            int pos = 0;
            for (int j = 0; j < q.size(); ++j) {
                if (v[q[j]] < v[q[pos]]) {
                    pos = j;
                }
            }
            s[i] = q[pos];
            ++v[s[i]];
        }
    }
    int mx = -inf, mn = inf;
    for (int i = 0; i < q.size(); ++i) {
        mx = max(mx, v[q[i]]);
        mn = min(mn, v[q[i]]);
    }
    if (mn != mx) {
        cout << "===" << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}