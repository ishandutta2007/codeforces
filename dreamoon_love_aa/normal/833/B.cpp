#include<bits/stdc++.h>
using namespace std;
const int SIZE = 35001;
int a[SIZE];
struct RG{
    int l, r;
    int v;
    vector<int> cnt;
    RG(int _n) {
        l = r = v = 0;
        cnt.resize(_n + 1);
    }
    int qq(int l2, int r2) {
        while(l2 < l) {
            if(!(cnt[a[--l]]++))v++;
        }
        while(r2 > r) {
            if(!(cnt[a[++r]]++))v++;
        }
        while(l2 > l) {
            if(!(--cnt[a[l++]]))v--;
        }
        while(r2 < r) {
            if(!(--cnt[a[r--]]))v--;
        }
        return v;
    }
}*rg;
void f(int dp[], int dp_pre[], int l, int r, int l2, int r2) {
    if(l2 > r2) { return; }
    int mm = (l2 + r2) / 2;
    int ma = -1;
    int pos = -1;
    for(int i = l; i <= r && i < mm; i++) {
        int v = dp_pre[i] + rg->qq(i + 1, mm);
        if(v > ma) {
            ma = v;
            pos = i;
        }
    }
    dp[mm] = ma;
    f(dp, dp_pre, l, pos, l2, mm - 1);
    f(dp, dp_pre, pos, r, mm + 1, r2);
}
int dp[2][SIZE];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    rg = new RG(n);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[0][i] = -n;
    for(int i = 1; i <= k; i++) {
        f(dp[i & 1], dp[(i & 1) ^ 1], i - 1, n - 1, i, n);
    }
    printf("%d\n", dp[k & 1][n]);
}
int main() {
    solve();
    return 0;
}