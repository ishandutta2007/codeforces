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

const int max_n = 655555, p = 39, mod = 1000000103;
const int p2 = 41, mod2 = 1000000009;

int n, m, pw[max_n], pw2[max_n];
string s;
set<pair<int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    pw[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        pw[i] = (1LL * pw[i - 1] * p) % mod;
        pw2[i] = (1LL * pw2[i - 1] * p2) % mod2;
    }
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int h = s[0] - 'a' + 1;
        int h2 = s[0] - 'a' + 1;
        for (int j = 1; j < s.length(); ++j) {
            h = (1LL * h * p + s[j] - 'a' + 1) % mod;
            h2 = (1LL * h2 * p2 + s[j] - 'a' + 1) % mod2;
        }
        q.insert(make_pair(h, h2));
        //cout << "             + " << h << endl;
    }
    while (m--) {
        cin >> s;
        int h = s[0] - 'a' + 1;
        int h2 = s[0] - 'a' + 1;
        for (int j = 1; j < s.length(); ++j) {
            h = (1LL * h * p + s[j] - 'a' + 1) % mod;
            h2 = (1LL * h2 * p2 + s[j] - 'a' + 1) % mod2;
        }
        int f = 0;
        for (int i = 0; i < s.length(); ++i) {
            for (char c = 'a'; c <= 'c'; ++c) {
                if (c != s[i]) {
                    int na = ((h + 1LL * (c - s[i]) * pw[s.length() - i - 1]) % mod + mod) % mod;
                    int nb = ((h2 + 1LL * (c - s[i]) * pw2[s.length() - i - 1]) % mod2 + mod2) % mod2;
                    //cout << "          ? " << na << endl;
                    if (q.count(make_pair(na, nb))) {
                        f = 1;
                        break;
                    }
                }
            }
            if (f == 1) {
                break;
            }
        }
        if (f == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}