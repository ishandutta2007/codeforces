#include <map>
#include <set>
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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    int poz = 0;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] == '|') {
            poz = i;
            break;
        }
    }
    int l = poz, r = s1.length() - poz - 1;
    int x = abs(r - l);
    if (x <= s2.length() && (s2.length() - x) % 2 == 0) {
        if (l > r) {
            int f = 0;
            for (int i = 0; i < poz; ++i) {
                cout << s1[i];
            }
            for (int i = 0; i < (s2.length() - x) / 2; ++i) {
                cout << s2[f];
                ++f;
            }
            cout << "|";
            for (int i = poz + 1; i < s1.length(); ++i) {
                cout << s1[i];
            }
            for (int i = f; i < s2.length(); ++i) {
                cout << s2[i];
            }
        } else {
            int f = 0;
            for (int i = 0; i < poz; ++i) {
                cout << s1[i];
            }
            for (int i = poz; i < (s1.length() + s2.length() - 1) / 2; ++i) {
                cout << s2[f];
                ++f;
            }
            cout << "|";
            for (int i = poz + 1; i < s1.length(); ++i) {
                cout << s1[i];
            }
            for (int i = 0; i < (s2.length() - x) / 2; ++i) {
                cout << s2[f];
                ++f;
            }
        }
        return 0;
    }else {
    cout << "Impossible";
    }
    return 0;
}