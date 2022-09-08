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

int n;
string s;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == '*' && s[j] == '*') {
                int d = j - i, x = j, f = 0;
                for (int k = 0; k < 3; ++k) {
                    x += d;
                    if (x >= n || s[x] == '.') {
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    cout << "yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "no" << endl;
    return 0;
}