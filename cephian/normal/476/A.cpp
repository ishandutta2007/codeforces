#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int min;
    if (n % 2 == 0)
        min = n / 2;
    else
        min = (n - 1) / 2 + 1;
    int max = n;
    for (int i = min; i <= max; ++i) {
        if (i % m == 0) {
            printf("%d", i);
            fflush (stdout);
            return 0;
        }
    }

    printf("-1");
    fflush (stdout);
    return 0;
}