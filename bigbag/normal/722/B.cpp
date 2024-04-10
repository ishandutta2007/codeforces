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

const int max_n = 111, inf = 1111111111;

int n, p[max_n];
string s[max_n];

bool ok(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    getline(cin, s[0]);
    for (int i = 0; i < n; ++i) {
        getline(cin, s[i]);
        int c = 0;
        for (int j = 0; j < s[i].length(); ++j) {
            if (ok(s[i][j])) {
                ++c;
            }
        }
        if (c != p[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}