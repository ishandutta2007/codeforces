#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int m[5];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    for (int i = 0; i < 4; ++i) {
        cin >> m[i];
    }
    int f = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                if (i != j && i != k && j != k) {
                    int a = m[i], b = m[j], c = m[k];
                    if (a + b > c && a + c > b && b + c > a) {
                        cout << "TRIANGLE";
                        return 0;
                    }
                    if (a + b == c || a + c == b || b + c == a) {
                        f = 1;
                    }
                }
            }
        }
    }
    if (f == 1) {
        cout << "SEGMENT";
        return 0;
    }
    cout << "IMPOSSIBLE";
    return 0;
}