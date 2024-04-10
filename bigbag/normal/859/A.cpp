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

const int max_n = 1000111, inf = 1011111111;

int n, x, ans, used[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        used[x] = 1;
    }
    for (int i = 1; n < 25; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            ++n;
        }
    }
    x = 0;
    for (int i = 1; n; ++i) {
        if (used[i]) {
            --n;
        } else {
            ++x;
        }
    }
    printf("%d\n", x);
    return 0;
}