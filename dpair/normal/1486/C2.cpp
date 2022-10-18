#include <cstdio>
#include <algorithm>

inline int query(int l, int r) {
    if(l == r) return -114514;
    int x; printf("? %d %d\n", l, r); fflush(stdout);
    scanf("%d", &x); return x;
}


int main() {
    int n; scanf("%d", &n); const int cur = query(1, n);
    int l = 1, r = n, ans = 0; while(l < r) {
        int mid = (l + r) >> 1;
        if(cur > mid) {
            if(query(mid + 1, std::max(cur, r)) == cur) l = mid + 1;
            else r = mid;
        } else {
            if(query(std::min(cur, l), mid) == cur) r = mid;
            else l = mid + 1;
        } 
    } printf("! %d\n", l);
}