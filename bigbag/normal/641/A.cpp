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

int n, a[max_n], used[max_n];
char s[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int x = 0;
    while (true) {
        if (used[x]) {
            printf("INFINITE\n");
            return 0;
        }
        used[x] = 1;
        if (s[x] == '<') {
            x -= a[x];
        } else {
            x += a[x];
        }
        if (x < 0 || x >= n) {
            printf("FINITE\n");
            return 0;
        }
    }
    return 0;
}