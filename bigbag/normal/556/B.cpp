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

const int max_n = 1111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0]) {
        int x = n - a[0];
        for (int i = 0; i < n; ++i) {
            a[i] = (a[i] + n + (1 - 2 * (i % 2)) * x) % n;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != i) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}