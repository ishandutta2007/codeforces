#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1e6;
int a[SIZE];
long long dp[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = 0;
    }
    for(int i = 2; i <= n; i++) {
        if(a[i - 1] > a[i]) {
            dp[1] += a[i - 1] - a[i];
            dp[i] -= a[i - 1] - a[i];
        } else {
            dp[i] += a[i] - a[i - 1];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i] > a[i]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}