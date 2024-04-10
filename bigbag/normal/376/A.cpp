#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    cin >> s;
    long long len = s.length(), poz, l = 0, r = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '^') {
            poz = i;
            break;
        }
    }
    for (int i = 0; i < poz; ++i) {
        if (s[i] != '=') {
            l += (poz - i) * (s[i] - '0');
        }
    }
    for (int i = poz + 1; i < len; ++i) {
        if (s[i] != '=') {
            r += (i - poz) * (s[i] - '0');
        }
    }
    if (l > r) {
        cout << "left" << endl;
    }
    if (l < r) {
        cout << "right" << endl;
    }
    if (l == r) {
        cout << "balance" << endl;
    }
    return 0;
}