#include<bits/stdc++.h>
using namespace std;
int n;
int a[200000];
int rht[200000], lft[200000];
int dp[200000];
int stk[200000];
int m;
void init() {
    m = 0;
}
int add(int v) {
    int depth = 1;
    while(m > 0 && stk[m - 1] > v) {
        m--;
        depth = max(depth, dp[m] + 1);
    }
    depth = max(depth, m + 1);
    dp[m] = depth;
    stk[m++] = v;
    return depth;
}
int main() {
    scanf("%d", &n);
    int one_pos = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == 1) {
            one_pos = i;
        }
    }
    rotate(a, a + one_pos, a + n);
    init();
    for(int i = 1; i < n; i++) {
        rht[i] = max(rht[i - 1], add(a[i]));
    }
    init();
    for(int i = n - 1; i >= 0; i--) {
        lft[n-i] = max(lft[n - i - 1], add(a[i]));
    }
    int mi = n + 1;
    int best_pos = -1;
    for(int i = 0; i < n; i++) {
        if(max(lft[i], rht[n - 1 - i]) < mi) {
            mi = max(lft[i], rht[n - 1 - i]);
            best_pos = i;
        }
    }
    printf("%d %d\n", mi + 1, (one_pos - best_pos + n) % n);
    return 0;
}