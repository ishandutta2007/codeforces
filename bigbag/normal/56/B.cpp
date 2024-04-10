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

const int max_n = 1111, inf = 111111111;

int n, a[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] != i) {
            for (int j = a[i] + 1; j <= n; ++j) {
                if (a[j] != j) {
                    cout << "0 0\n";
                    return 0;
                }
            }
            for (int j = i + 1; j <= a[i]; ++j) {
                if (a[j] != a[i] - j + i) {
                    cout << "0 0\n";
                    return 0;
                }
            }
            cout << i << ' ' << a[i] << endl;
            return 0;
        }
    }
    cout << "0 0\n";
    return 0;
}