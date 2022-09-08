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

const int max_n = 333, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    while (a[0] != 0) {
        --a[0];
        cout << "PRL";
    }
    cout << "R";
    for (int i = 1; i < n; ++i) {
        while (a[i] != 0) {
            --a[i];
            cout << "PLR";
        }
        if (i + 1 != n) {
            cout << "R";
        }
    }
    return 0;
}