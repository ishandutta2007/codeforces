#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int min = 999999;
    int en = 0;
    for (int i = 0; i < n; ++i) {
        int nen;
        scanf("%d", &nen);
        en -= nen;
        min = std::min(min, en);
        en += nen;
    }
    printf("%d", max(-min, 0));
    return 0;
}