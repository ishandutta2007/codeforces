#include <iostream>
#include <cstdio>

int abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

using namespace std;

int main() {
    int aq, bq;
    scanf("%d %d", &aq, &bq);
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= 6; ++i) {
        int as = abs(i - aq);
        int bs = abs(i - bq);
        if (as == bs)
            ++c;
        else if (as > bs)
            ++b;
        else
            ++a;
    }
    printf("%d %d %d", a, c, b);
    return 0;
}