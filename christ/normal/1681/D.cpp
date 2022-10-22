#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
map<long long, int> dp;
int solve (long long n, long long x) {
    if (x >= n) return 0;
    if (dp.count(x)) return dp[x];
    vector<bool> can(10);
    long long cur = x;
    while (cur > 0) {
        can[cur%10]=true;
        cur/=10;
    }
    int ret = 1e9 + 1;
    for (int i = 2; i < 10; i++) if (can[i]) ret = min(ret,solve(n,x*i) + 1); 
    return dp[x] = ret;
}
int main () {
    int n; long long x;
    scanf ("%d %lld",&n,&x);
    long long want = 1;
    for (int i = 1; i < n; i++) want *= 10;
    int ret = solve(want,x);
    printf ("%d\n",ret > 1e9 ? -1 : ret);
    return 0;
}