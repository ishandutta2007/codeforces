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

const int max_n = 2222, inf = 1011111111;

int n, a[max_n], b[max_n], used[5111222], c;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        used[a[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        used[b[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (used[a[i] ^ a[j]]) {
                ++c;
            }
        }
    }
    c %= 2;
    if (c) {
        printf("Koyomi\n");
    } else {
        printf("Karen\n");
    }
    return 0;
}