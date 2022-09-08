#include <bits/stdc++.h>

using namespace std;

const int max_n = 222222;

int ans;
char a[max_n], b[max_n];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%s%s", a, b);
    int n = strlen(a);
    int m = strlen(b);
    --n;
    --m;
    while (n >= 0 && m >= 0 && a[n] == b[m]) {
        --n;
        --m;
    }
    printf("%d\n", n + m + 2);
    return 0;
}