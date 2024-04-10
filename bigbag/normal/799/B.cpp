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

const int max_n = 222222, inf = 1011111111;

int n, a[max_n], c1[max_n], c2[max_n];
vector<int> all[5][5];

void proc(int mn, int c) {
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            if (i == c || j == c) {
                if (all[i][j].size()) {
                    if (mn == all[i][j].back()) {
                        all[i][j].pop_back();
                        return;
                    }
                }
            }
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c1[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &c2[i]);
        all[c1[i]][c2[i]].push_back(a[i]);
    }
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            sort(all[i][j].begin(), all[i][j].end());
            reverse(all[i][j].begin(), all[i][j].end());
        }
    }
    scanf("%d", &n);
    while (n--) {
        int c;
        scanf("%d", &c);
        int mn = inf;
        for (int i = 1; i < 4; ++i) {
            for (int j = 1; j < 4; ++j) {
                if (i == c || j == c) {
                    if (all[i][j].size()) {
                        mn = min(mn, all[i][j].back());
                    }
                }
            }
        }
        if (mn == inf) {
            mn = -1;
        } else {
            proc(mn, c);
        }
        printf("%d ", mn);
    }
    printf("\n");
    return 0;
}