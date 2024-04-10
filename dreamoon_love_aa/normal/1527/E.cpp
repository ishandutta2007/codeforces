#include<bits/stdc++.h>
using namespace std;
const int SIZE = 35001;
int a[SIZE];
int pre[SIZE];
int nxt[SIZE];
struct RG{
    int l, r;
    int v;
    RG() {
        l = r = v = 0;
    }
    int qq(int l2, int r2) {
        while(l2 < l) {
            if(nxt[--l] <= r) {
                v += nxt[l] - l;
            }
        }
        while(r2 > r) {
            if(pre[++r] >= l) {
                v += r - pre[r];
            }
        }
        while(l2 > l) {
            if(nxt[l] <= r) {
                v -= nxt[l] - l;
            }
            l++;
        }
        while(r2 < r) {
            if(pre[r] >= l) {
                v -= r - pre[r];
            }
            r--;
        }
        return v;
    }
}*rg;
void f(int dp[], int dp_pre[], int l, int r, int l2, int r2) {
    if(l2 > r2) { return; }
    int mm = (l2 + r2) / 2;
    int mi = 1e9;
    int pos = -1;
    for(int i = l; i <= r && i < mm; i++) {
        int v = dp_pre[i] + rg->qq(i + 1, mm);
        if(v < mi) {
            mi = v;
            pos = i;
        }
    }
    dp[mm] = mi;
    f(dp, dp_pre, l, pos, l2, mm - 1);
    f(dp, dp_pre, pos, r, mm + 1, r2);
}
int dp[2][SIZE];
int lt[SIZE];
void solve() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(lt[a[i]]){
            pre[i] = lt[a[i]];
        }else {
            pre[i] = i;
        }
        lt[a[i]] = i;
    }
    memset(lt, 0, sizeof(lt));
    for(int i = n; i > 0; i--) {
        if(lt[a[i]]) {
            nxt[i] = lt[a[i]];
        } else {
            nxt[i] = i;
        }
        lt[a[i]] = i;
    }
    rg = new RG();
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) dp[0][i] = 2e9;
    for(int i = 1; i <= k; i++) {
        f(dp[i & 1], dp[(i & 1) ^ 1], i - 1, n - 1, i, n);
    }
    printf("%d\n", dp[k & 1][n]);
}
int main() {
    solve();
    return 0;
}