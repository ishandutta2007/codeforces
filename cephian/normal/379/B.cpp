#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int left = 0;
    int vals[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &vals[i]);
        left += vals[i];
    }
    int i = 0;
    while (true) {
        if (vals[i] > 0) {
            printf("P");
            --left;
            --vals[i];
        }
        if (left == 0)
            break;
        if (i > 0 && vals[i - 1] > 0) {
            printf("L");
            --i;
        } else if (i != n - 1) {
            printf("R");
            ++i;
        } else {
            printf("L");
            --i;
        }
    }
    printf("\n");
    return 0;
}