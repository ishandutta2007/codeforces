#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    if (n % 2) {
        printf("%d\n", 2 * (n / 2 + 2) * (n / 2 + 1));
    }
    else {
        printf("%d\n", (n / 2 + 1) * (n / 2 + 1));
    }
}