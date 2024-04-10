#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

int l;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    l = s.length();
    if (s[0] == '@' || s[l - 1] == '@') {
        cout << "No solution" << endl;
        return 0;
    }
    vector <int> v;
    v.push_back(-2);
    for (int i = 0; i < l; ++i) {
        if (s[i] == '@') v.push_back(i);
    }
    if (v.size() == 1) {
        cout << "No solution" << endl;
        return 0;
    }
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] - v[i - 1] <= 2) {
            cout << "No solution" << endl;
            return 0;
        }
    }
    for (int i = 1; i < v.size(); ++i) {
        for (int j = v[i - 1] + 2; j <= v[i] + 1; ++j) {
            cout << s[j];
        }
        if (i + 1 != v.size()) {
            cout << ',';
        } else {
            for (int j = v[i] + 2; j < l; ++j) {
                cout << s[j];
            }
        }
    }
    return 0;
}