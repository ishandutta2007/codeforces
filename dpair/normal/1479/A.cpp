#include <cstdio>

void solve(int l, int r) {
    if(l == r) { printf("! %d\n", l); fflush(stdout); return ; }
    int mid = (l + r) >> 1;
    int x, y; printf("? %d\n", mid); fflush(stdout); scanf("%d", &x);
    printf("? %d\n", mid + 1); fflush(stdout); scanf("%d", &y);
    x < y? solve(l, mid) : solve(mid + 1, r);
}

int main() {
    int n; scanf("%d", &n);
    solve(1, n);
}