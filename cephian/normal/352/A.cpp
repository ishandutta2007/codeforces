#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int n5 = 0, n0 = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0)
            ++n0;
        else
            ++n5;
    }
    if (n0 == 0) {
        printf("-1\n");
        fflush(stdout);
        return 0;
    }
    int m5 = (n5 / 9) * 9;
    if (m5 == 0) {
        printf("0");
        fflush(stdout);
        return 0;
    }
    for (int i = 0; i < m5; ++i) {
        printf("5");
    }
    for (int i = 0; i < n0; ++i) {
        printf("0");
    }
    printf("\n");
    fflush(stdout);
    return 0;
}