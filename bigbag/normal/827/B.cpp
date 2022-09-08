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

const int max_n = 201111, inf = 1011111111;

int n, k, last[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    int cnt = n - 1 - k;
    int l = cnt / k;
    int num = cnt - l * k;
    if (num == 0) {
        printf("%d\n", 2 * l + 2);
    } else if (num == 1) {
        printf("%d\n", 2 * l + 3);
    } else {
        printf("%d\n", 2 * l + 4);
    }
    int first = k + 1;
    for (int i = 1; i <= k; ++i) {
        int c = l;
        if (i <= num) {
            ++c;
        }
        int last = i;
        for (int j = 0; j < c; ++j) {
            printf("%d %d\n", last, first);
            last = first;
            ++first;
        }
        printf("%d %d\n", last, n);
    }
    return 0;
}