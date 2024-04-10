#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int ex[3];
    std::fill(ex, ex + 3, 0);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        ex[i % 3] += tmp;
    }
    int max_i;
    int max = -1;
    for (int i = 0; i < 3; ++i) {
        if (ex[i] > max) {
            max = ex[i];
            max_i = i;
        }
    }
    if (max_i == 0) {
        printf("chest");
    } else if (max_i == 1) {
        printf("biceps");
    } else {
        printf("back");
    }
    printf("\n");
    return 0;
}