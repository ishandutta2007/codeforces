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

const int max_n = 1011111;

int n, k, f[max_n], used[222];
char s[max_n];

int main() {
    scanf("%d%d%s", &n, &k, s);
    for (int i = n - 1; i >= 0; --i) {
        if (used[s[i]] == 0) {
            used[s[i]] = 1;
            f[i] = 1;
        }
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; ++i) {
        if (used[s[i]] == 0) {
            --k;
            used[s[i]] = 1;
        }
        if (k < 0) {
            printf("YES\n");
            return 0;
        }
        if (f[i]) {
            ++k;
        }
    }
    printf("NO\n");
    return 0;
}