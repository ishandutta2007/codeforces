#include <bits/stdc++.h>

using namespace std;

const int max_n = 202222, inf = 1000111222;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, sx, sy, x[max_n], y[max_n];

bool is_in(int l, int r, int x) {
    if (l > r) {
        swap(l, r);
    }
    return l <= x && x <= r;
}

int func(int fx, int fy) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (is_in(x[i], sx, fx) && is_in(y[i], sy, fy)) {
            ++res;
        }
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%d", &n, &sx, &sy);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &y[i]);
    }
    int best = 0;
    for (int i = 1; i < 4; ++i) {
        if (func(sx + dx[i], sy + dy[i]) > func(sx + dx[best], sy + dy[best])) {
            best = i;
        }
    }
    printf("%d\n", func(sx + dx[best], sy + dy[best]));
    printf("%d %d\n", sx + dx[best], sy + dy[best]);
    return 0;
}