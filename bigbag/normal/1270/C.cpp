#include <bits/stdc++.h>

using namespace std;

const int max_n = 100111, inf = 1000111222;

int t, n;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        long long a = 0, b = 0;
        while (n--) {
            int x;
            scanf("%d", &x);
            a += x;
            b ^= x;
        }
        printf("2\n%I64d %I64d\n", b, a + b);
    }
    return 0;
}