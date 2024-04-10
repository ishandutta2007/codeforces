#include<bits/stdc++.h>
using namespace std;
const int MN = 1e6+5, LOG = 60, MOD = 998244353, ADD = 9;
using pii = pair<int,int>;
using ll = long long;
using ld = long double;
const ld EPS = 1e-10;
ld dp[MN];
int cnt[MN];
char s[MN];
int n,l;
bool lower (char c) {return islower(c)?1:0;}
bool upper(char c) {return isupper(c)?1:0;}
ld solve1 (ld cost) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + lower(s[i]);
        cnt[i] = cnt[i-1];
        if (i >= l) {
            if (dp[i-l] + cost < dp[i]) {
                dp[i] = dp[i-l] + cost;
                cnt[i] = cnt[i-l] + 1;
            }
        } else {
            if (cost < dp[i]) {
                dp[i] = cost;
                cnt[i] = 1;
            }
        }
    }
    return dp[n];
}
ld solve2 (ld cost) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1] + upper(s[i]);
        cnt[i] = cnt[i-1];
        if (i >= l) {
            if (dp[i-l] + cost < dp[i]) {
                dp[i] = dp[i-l] + cost;
                cnt[i] = cnt[i-l] + 1;
            }
        } else {
            if (cost < dp[i]) {
                dp[i] = cost;
                cnt[i] = 1;
            }
        }
    }
    return dp[n];
}
int main () {
	int k;
	scanf ("%d %d %d",&n,&k,&l);
	scanf ("%s",s+1);
    ld low = 0.0, high = (ld)1e9, mid=0.0;
    while (high-low > EPS) {
        mid = (low+high)/2;
        solve1(mid);
        if (cnt[n] > k) low = mid;
        else high = mid;
    }
    solve1(high);
    int ans = (int)roundl(dp[n]-high*k);
    low = 0, high = 1e9;
    while (high-low > EPS) {
        mid = (low+high)/2;
        solve2(mid);
        if (cnt[n] > k) low = mid;
        else high = mid;
    }
    solve2(high);
	printf ("%d\n",min(ans,(int)roundl(dp[n]-high*k)));
	return 0;
}