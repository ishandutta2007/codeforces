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

const int max_n = 1011, inf = 1011111111;

int n, a[max_n][5];
vector<int> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        int f = 1;
        for (int j = 0; j < min(n, 100) && f; ++j) {
            for (int k = j + 1; k < min(n, 100); ++k) {
                if (i != j && i != k) {
                    int x = 0;
                    for (int q = 0; q < 5; ++q) {
                        x += (a[j][q] - a[i][q]) * (a[k][q] - a[i][q]);
                    }
                    if (x > 0) {
                        f = 0;
                        break;
                    }
                }
            }
        }
        if (f) {
            ans.push_back(i + 1);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}