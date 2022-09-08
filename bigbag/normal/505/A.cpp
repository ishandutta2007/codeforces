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

bool is_palindrom(const string &s) {
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    for (int i = 0; i <= s.length(); ++i) {
        for (char c = 'a'; c <= 'z'; ++c) {
            string q = s.substr(0, i) + c + s.substr(i);
            if (is_palindrom(q)) {
                cout << q << endl;
                return 0;
            }
        }
    }
    cout << "NA" << endl;
    return 0;
}