#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int vals[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vals[i]);
    }
    sort(vals, vals + n);

    int teams = 0;
    for (int i = 2; i < n; i += 3) {
        if (5 - vals[i] >= k)
            ++teams;
        else
            break;
    }
    printf("%d\n", teams);
    return 0;
}