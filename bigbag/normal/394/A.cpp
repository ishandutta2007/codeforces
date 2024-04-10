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

int cnt[5];
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int f = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '|') {
            ++cnt[f];
        } else {
            ++f;
        }
    }
    int a = cnt[0], b = cnt[1], c = cnt[2];
    if (a + b == c + 2) {
        if (a > 1) {
            --a;
        } else {
            --b;
        }
        ++c;
    }
    if (a + b + 2 == c) {
        --c;
        ++a;
    }
    if (a + b != c) {
        cout << "Impossible" << endl;
    } else {
        for (int i = 0; i < a; ++i) {
            cout << "|";
        }
        cout << "+";
        for (int i = 0; i < b; ++i) {
            cout << "|";
        }
        cout << "=";
        for (int i = 0; i < c; ++i) {
            cout << "|";
        }
    }
    return 0;
}