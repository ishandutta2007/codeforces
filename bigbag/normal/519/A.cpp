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

int ans[2];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            int t = 0;
            if (s[j] >= 'a' && s[j] <= 'z') {
                t = 1;
                s[j] = s[j] - 'a' + 'A';
            }
            int x = 0;
            if (s[j] == 'Q') x = 9;
            if (s[j] == 'R') x = 5;
            if (s[j] == 'B') x = 3;
            if (s[j] == 'N') x = 3;
            if (s[j] == 'P') x = 1;
            ans[t] += x;
        }
    }
    if (ans[0] > ans[1]) {
        cout << "White" << endl;
    } else if (ans[0] < ans[1]) {
        cout << "Black" << endl;
    } else {
        cout << "Draw" << endl;
    }
    return 0;
}