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

const int max_n = 3033, inf = 1011111111;
const string ok_c = "aeiou";

int n;
string s;
vector<string> ans;

bool ok(char c) {
    for (int i = 0; i < ok_c.length(); ++i) {
        if (ok_c[i] == c) {
            return true;
        }
    }
    return false;
}

bool bad(const string &t) {
    if (t.length() >= 3) {
        int f = 0;
        for (int i = 1; i < t.length(); ++i) {
            if (t[i] != t[0]) {
                f = 1;
                break;
            }
        }
        if (f == 0) {
            return false;
        }
        for (int i = 0; i < t.length(); ++i) {
            if (ok(t[i])) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int last = 0, cnt = 0;
    for (int i = 0; i < s.length(); ++i) {
        int pos = max(last, i - 2);
        string t = s.substr(pos, i - pos + 1);
        if (bad(t)) {
            ans.push_back(s.substr(last, i - last));
            last = i;
            continue;
        }
    }
    if (last < s.length()) {
        ans.push_back(s.substr(last));
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}