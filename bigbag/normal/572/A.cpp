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

int n1, n2, k1, k2, a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    for (int i = 0; i < n1; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n2; ++i) {
        scanf("%d", &b[i]);
    }
    sort(a, a + n1);
    sort(b, b + n2);
    if (a[k1 - 1] < b[n2 - k2]) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}