#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }
    int left = (n - 1) * 10 + sum;
    if (left > d) {
        printf("-1");
        fflush(stdout);
        return 0;
    }
    printf("%d", (d - sum) / 5);
    fflush(stdout);
    return 0;
}