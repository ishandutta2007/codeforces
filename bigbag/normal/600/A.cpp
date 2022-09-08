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

string s;

bool ok(string s) {
    if (s == "0") {
        return true;
    }
    if (s.length() == 0) {
        return false;
    }
    if (s[0] == '0') {
        return false;
    }
    for (int i = 0; i < s.length(); ++i) {
        if ('0' <= s[i] && s[i] <= '9') {
            continue;
        }
        return false;
    }
    return true;
}

vector<string> a, b;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    string q = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == ',' || s[i] == ';') {
            if (ok(q)) {
                a.push_back(q);
            } else {
                b.push_back(q);
            }
            q = "";
        } else {
            q += s[i];
        }
    }
    if (ok(q)) {
        a.push_back(q);
    } else {
        b.push_back(q);
    }
    if (a.size() == 0) {
        cout << "-" << endl;
    } else {
        cout << "\"";
        for (int i = 0; i < a.size(); ++i) {
            cout << a[i];
            if (i + 1 != a.size()) {
                cout << ",";
            }
        }
        cout << "\"" << endl;
    }
    if (b.size() == 0) {
        cout << "-" << endl;
    } else {
        cout << "\"";
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i];
            if (i + 1 != b.size()) {
                cout << ",";
            }
        }
        cout << "\"" << endl;
    }
    return 0;
}