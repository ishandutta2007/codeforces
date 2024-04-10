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

const int max_n = 1111, inf = 111111111;

string norm(string s) {
    string res = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != '-' && s[i] != ';' && s[i] != '_') {
            if (s[i] >= 'a' && s[i] <= 'z') {
                res += s[i] - 'a' + 'A';
            } else {
                res += s[i];
            }
        }
    }
    return res;
}

int n;
string s[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s[0] >> s[1] >> s[2] >> n;
    s[0] = norm(s[0]);
    s[1] = norm(s[1]);
    s[2] = norm(s[2]);
    for (int i = 0; i < n; ++i) {
        string q;
        cin >> q;
        q = norm(q);
        if (q == s[0] + s[1] + s[2] || q == s[0] + s[2] + s[1] || q == s[1] + s[0] + s[2] || q == s[1] + s[2] + s[0] || q == s[2] + s[0] + s[1] || q == s[2] + s[1] + s[0]) {
            cout << "ACC" << endl;
        } else {
            cout << "WA" << endl;
        }
    }
    return 0;
}