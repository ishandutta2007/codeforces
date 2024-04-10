#include <bits/stdc++.h>

const int MAXN = 1010;

int n, h;
int a[MAXN];

bool check(int mid) {
    std::vector<int> vec;
    for (int i = 0; i < mid; ++i) {
        vec.push_back(a[i]);
    }
    std::sort(vec.rbegin(), vec.rend());
    int now = 0;
    for (int i = 0; i < mid; i += 2) {
        if (now > h) break;
        now += vec[i];
    }
    return now <= h;
}

int main() {
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    int left = 0, right = n, ans = -1;
    //check(3);
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (check(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}