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

const int max_n = 1111111, inf = 111111111;

int len, x, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> len >> x;
    if (len == 1 && x != 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 1; i <= 9; ++i) {
        int p = 0;
        a[0] = i;
        for (int j = 0; j < len; ++j) {
            a[j + 1] = (a[j] * x + p) % 10;
            p = (a[j] * x + p) / 10;
        }
        if (p == 0 && a[len - 1] != 0 && a[len] == a[0]) {
            for (int j = len - 1; j >= 0; --j) {
                cout << a[j];
            }
            cout << endl;
            return 0;
        }
    }
    cout << "Impossible" << endl;
    return 0;
}