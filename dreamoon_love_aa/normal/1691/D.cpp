#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB push_back
using namespace std;
const int SIZE = 1 << 18;
long long mi_prefix[SIZE];
long long dp[SIZE];
int stk[SIZE];
int a[SIZE];
int sn;
void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long prefix_sum = 0;
    sn = 0;
    for(int i = 1; i <= n; i++) {
        long long tmp = prefix_sum;
        while(sn && a[i] >= a[stk[sn - 1]]) {
            sn--;
            tmp = min(tmp, mi_prefix[sn]);
        }
        mi_prefix[sn] = tmp;
        if(sn) dp[sn] = min(dp[sn - 1], tmp + a[i]);
        else dp[sn] = tmp + a[i];
        prefix_sum += a[i];
        if(dp[sn] < prefix_sum) {
            cout << "NO\n";
            return;
        }
        stk[sn++] = i;
    }
    cout << "YES\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}