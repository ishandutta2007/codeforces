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

const int max_n = 111111, inf = 1011111111;

int n, m, f[max_n], g[max_n], h[max_n];
vector<int> v[max_n];

void wa() {
    printf("-1\n");
    exit(0);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        v[f[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (v[i].size()) {
            ++m;
            int f = 0;
            for (int j = 0; j < v[i].size(); ++j) {
                g[v[i][j]] = m;
                if (v[i][j] == i) {
                    f = 1;
                }
            }
            if (f == 0) {
                wa();
            }
            h[m] = i;
        }
    }
    printf("%d\n", m);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", g[i]);
    }
    printf("\n");
    for (int i = 1; i <= m; ++i) {
        printf("%d ", h[i]);
    }
    printf("\n");
    return 0;
}