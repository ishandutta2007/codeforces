#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }
    printf("%f", ((double) sum) / n);
    return 0;
}