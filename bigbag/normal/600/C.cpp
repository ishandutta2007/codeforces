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

const int max_n = 222222, inf = 1111111111;

int a[333];
string s, ans;
vector<char> v;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    ans = s;
    for (int i = 0; i < s.length(); ++i) {
        ++a[s[i]];
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (a[c] % 2) {
            v.push_back(c);
        }
    }
    if (v.size()) {
        int poz = 0;
        for (int i = v.size() - 1; i > poz; --i) {
            --a[v[i]];
            ++a[v[poz]];
            ++poz;
        }
        if (v.size() % 2) {
            --a[v[v.size() / 2]];
            ans[s.length() / 2] = v[v.size() / 2];
        }
    }
    int l = 0, r = s.length() - 1;
    for (char c = 'a'; c <= 'z'; ++c) {
        while (a[c]) {
            ans[l] = c;
            ans[r] = c;
            --r;
            ++l;
            a[c] -= 2;
        }
    }
    cout << ans << endl;
    return 0;
}