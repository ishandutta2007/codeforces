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

int n, k, cnt;
char a[max_n][max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (cnt == k) {
                a[i][j] = 'S';
                continue;
            }
            if ((i % 2) ^ (j % 2) == 0) {
                a[i][j] = 'L';
                ++cnt;
            } else {
                a[i][j] = 'S';
            }
        }
    }
    if (cnt < k) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}