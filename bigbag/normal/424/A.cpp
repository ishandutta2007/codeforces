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

int n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'x') {
            ++cnt1;
        } else {
            ++cnt2;
        }
    }
    if (cnt1 < cnt2) {
        cout << (cnt2 - cnt1) / 2 << endl;
        for (int i = 0; i < s.length(); ++i) {
            if (cnt1 < cnt2 && s[i] == 'X') {
                ++cnt1;
                --cnt2;
                s[i] = 'x';
            }
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << (cnt1 - cnt2) / 2 << endl;
        for (int i = 0; i < s.length(); ++i) {
            if (cnt2 < cnt1 && s[i] == 'x') {
                ++cnt2;
                --cnt1;
                s[i] = 'X';
            }
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}