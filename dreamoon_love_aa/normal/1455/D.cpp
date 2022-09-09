#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int n, x;
int a[514];
bool valid(int st) {
    for(int i = st + 1; i < n; i++) {
        if(a[i] > a[i + 1]) {
            return 0;
        }
    }
    return 1;
}
int dp[514];
void update(int &_x, int v) {
    if(_x == -1 || _x > v) {
        _x = v;
    }
}
void solve() {
    scanf("%d%d", &n, &x);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    if(valid(0)) {
        puts("0");
        return;
    }
    a[n + 1] = 501;
    for(int i = 1; i <= n; i++) {
        dp[i] = -1;
    }
    int an = 501;
    for(int i = 1; i <= n; i++) {
        bool err = 0;
        for(int j = i - 1; j >= 1; j--) {
            if(a[j] < a[i] && a[j] <= a[i + 1] && dp[j] != -1) {
                if(j + 1 == i || a[j] >= a[i - 1]) {
                    update(dp[i], dp[j] + 1);
                }
            }
            if(j + 1 < i) {
                if(a[j] > a[j + 1]) {
                    err = 1;
                    break;
                }
            }
        }
        if(x >= a[i - 1] && !err && x <= a[i + 1] && x < a[i]) {
            dp[i] = 1;
        }
        if(dp[i] != -1 && valid(i)) {
            an = min(an, dp[i]);
        }
        //printf("dp[%d] = %d\n", i, dp[i]);
    }
    if(an == 501) {
        an = -1;
    }
    printf("%d\n", an);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}