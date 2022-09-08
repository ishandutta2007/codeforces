#include <bits/stdc++.h>

using namespace std;

const int max_n = 15055, inf = 1000111222;

int n;
vector<pair<int, int>> ans;

void make_eq(int l, int r) {
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    make_eq(l, mid);
    make_eq(mid + 1, r);
    int d = mid - l + 1;
    for (int i = l; i <= mid; ++i) {
        ans.push_back({i, i + d});
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int len = 1;
    while (len * 2 <= n) {
        len *= 2;
    }
    make_eq(1, len);
    make_eq(n - len + 1, n);
    printf("%d\n", ans.size());
    for (auto p : ans) {
        printf("%d %d\n", p.first, p.second);
    }
    return 0;
}