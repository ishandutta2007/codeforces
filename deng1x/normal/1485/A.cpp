//
// Created by Junjie Wu on 2021/2/20.
//

#include <bits/stdc++.h>

int calc(int a, int b) {
    int ret = 0;
    while (a) {
        ++ret;
        a /= b;
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int a, b, ans = 0;
        scanf("%d%d", &a, &b);
        if (b == 1) {
            ++b;
            ++ans;
        }
        for (; ; ) {
            int now = calc(a, b);
            int next = calc(a, b + 1);
            if (now >= next + 1) {
                ++b;
                ++ans;
            } else {
                break;
            }
        }
        ans += calc(a, b);
        printf("%d\n", ans);
    }
    return 0;
}