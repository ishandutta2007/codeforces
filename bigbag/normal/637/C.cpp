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

const int max_n = 1011, inf = 1111111111;

int n;
char s[max_n][11];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s[i]);
    }
    int ans = 6;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int cnt = 0;
            for (int k = 0; k < 6; ++k) {
                if (s[i][k] != s[j][k]) {
                    ++cnt;
                }
            }
            ans = min(ans, (cnt - 1) / 2);
        }
    }
    printf("%d\n", ans);
    return 0;
}