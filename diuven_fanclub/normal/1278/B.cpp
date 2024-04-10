#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int _t = 0; _t < t; _t++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) swap(a, b);
        int x = b - a, ans;
        for (ans = 0; ; ans++) {
            int sum = ans * (ans + 1) / 2;
            if (x % 2 != sum % 2) continue;
            if (x > sum) continue;
            break;
        }
        printf("%d\n", ans);
    }
}