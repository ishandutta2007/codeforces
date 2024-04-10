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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s;
    int h, e, l1, l2, o;
    h = e = l1 = l2 = o = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'h') {
            h = i;
            break;
        }
    }
    for (int i = h + 1; i < s.length(); ++i) {
        if (s[i] == 'e') {
            e = i;
            break;
        }
    }
    for (int i = e + 1; i < s.length(); ++i) {
        if (s[i] == 'l') {
            l1 = i;
            break;
        }
    }
    for (int i = l1 + 1; i < s.length(); ++i) {
        if (s[i] == 'l') {
            l2 = i;
            break;
        }
    }
    for (int i = l2 + 1; i < s.length(); ++i) {
        if (s[i] == 'o') {
            o = i;
            break;
        }
    }
    if (h < e && e < l1 && l1 < l2 && l2 < o) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}