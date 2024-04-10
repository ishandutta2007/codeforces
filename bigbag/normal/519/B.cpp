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

const int max_n = 111111, inf = 1111111111;

int n, a[3][max_n];
map<int, int> q[3];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) {
        for (int j = i; j < n; ++j) {
            scanf("%d", &a[i][j]);
            ++q[i][a[i][j]];
        }
        if (i) {
            for (int j = i - 1; j < n; ++j) {
                if (q[i - 1][a[i - 1][j]] != q[i][a[i - 1][j]]) {
                    printf("%d\n", a[i - 1][j]);
                    break;
                }
            }
        }
    }
    return 0;
}