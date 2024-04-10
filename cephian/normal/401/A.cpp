#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        sum += tmp;
    }
    if (sum < 0)
        sum = -sum;
    int find = 0;
    while (sum >= x) {
        sum -= x;
        ++find;
    }
    if (sum != 0)
        ++find;
    printf("%d", find);
}