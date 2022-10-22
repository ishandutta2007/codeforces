//
// Created by Junjie Wu on 2021/2/16.
//
#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10;

int n;
int a[MAX_N];

int query(int pos) {
    if (a[pos] != 0) return a[pos];
    printf("? %d\n", pos);
    fflush(stdout);
    scanf("%d", a + pos);
    return a[pos];
}

int main() {
    scanf("%d", &n);
    a[0] = a[n + 1] = MAX_N;

    int left = 1, right = n;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (query(mid - 1) > query(mid) && query(mid) < query(mid + 1)) {
            printf("! %d\n", mid);
            return 0;
        }
        if (query(mid - 1) < query(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return 0;
}