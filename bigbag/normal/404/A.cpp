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

const int max_n = 333, inf = 111111111;

int n;
string s[max_n];
set<char> s1, s2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            if (i != j && i != n - j - 1) {
                s2.insert(s[i][j]);
            } else {
                s1.insert(s[i][j]);
            }
        }
    }
    if (s1.size() != 1 || s2.size() != 1) {
        cout << "NO" << endl;
        return 0;
    }
    if (*s1.begin() == *s2.begin()) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}