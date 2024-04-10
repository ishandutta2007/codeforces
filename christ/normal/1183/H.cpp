#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
const int MN = 202, MOD = 1e9+7, B = 300;
#define all(x) (x).begin(),(x).end()
ll dp[105][105]; //dp[i][j] = number in prefix i with j things
ll sum[105];
char s[105];
int main() {
    int n; ll k;
    scanf ("%d %lld",&n,&k);
    scanf ("%s",s+1);
    dp[0][0] = 1; sum[0] = 1;
    for (int sz = 1; sz <= n; sz++) {
        for (int ed = sz; ed <= n; ed++) {
            for (int lst = ed-1; lst >= 0; lst--) {
                dp[sz][ed] += dp[sz-1][lst];
                if (s[lst] == s[ed]) break;
            }
            sum[sz] += dp[sz][ed];
        }
    }
    ll ret = 0;
    for (int sz = n; sz >= 0; sz--) {
        sum[sz] = min(sum[sz],k);
        ret += (n-sz)*sum[sz];
        k -= sum[sz];
        if (!k) break;
    }
    if (k>0) return !printf ("-1\n");
    printf ("%lld\n",ret);
    return 0;
}