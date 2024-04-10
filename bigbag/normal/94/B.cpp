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

int n, a[11][11];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for (int i = 1; i <= 5; ++i) {
        for (int j = i + 1; j <= 5; ++j) {
            for (int k = j + 1; k <= 5; ++k) {
                int sum = a[i][j] + a[i][k] + a[j][k];
                if (sum == 0 || sum == 3) {
                    cout << "WIN" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "FAIL" << endl;
    return 0;
}