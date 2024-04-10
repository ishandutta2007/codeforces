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

int n, used[255];
string s, ans;
vector<char> c;
vector<int> poz;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < s.length(); ++i) {
        used[s[i]] = 1;
        if (s[i] != s[s.length() - i - 1] && s[i] != '?' && s[s.length() - i - 1] != '?') {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?' && s[s.length() - i - 1] != '?') {
            s[i] = s[s.length() - i - 1];
        }
        if (s[i] != '?' && s[s.length() - i - 1] == '?') {
            s[s.length() - i - 1] = s[i];
        }
    }
    for (char i = 'a'; i < 'a' + n; ++i) {
        if (used[i] == 0) {
            c.push_back(i);
        }
    }
    reverse(c.begin(), c.end());
    ans = s;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '?' && s[s.length() - i - 1] == '?') {
            //s[i] = s[s.length() - i - 1];
            poz.push_back(i);
        }
    }
    int cnt = poz.size();
    if (cnt % 2 != 0) {
        ++cnt;
    }
    cnt /= 2;
    if (cnt < c.size()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int x = cnt - c.size();
    for (int i = 0; i < cnt; ++i) {
        if (i < x) {
            s[poz[i]] = 'a';
            s[s.length() - poz[i] - 1] = 'a';
        } else {
            s[poz[i]] = c[c.size() - 1];
            s[s.length() - poz[i] - 1] = c[c.size() - 1];
            c.pop_back();
        }
    }
    cout << s << endl;
    return 0;
}