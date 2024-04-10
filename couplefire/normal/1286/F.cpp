#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 20;

int n, dp[1<<N]; ll arr[N], sum[1<<N];
bitset<1<<N> work;

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; ++i)
        cin >> arr[i], sum[1<<i] = arr[i], work[1<<i] = (arr[i]==0ll);
    for(int m = 1, end = (1<<n); m<end; ++m){
        sum[m] = sum[m^(m&(-m))]+sum[m&(-m)]; ll siz = __builtin_popcount(m);
        if((sum[m]+siz+1)&1) continue;
        for(int s = (m&(m-1)); s; s = (s-1)&m)
            if(abs(sum[s]-sum[m^s])<siz) {work.set(m); break;}
    }
    for(int m = 0, end = (1<<n); m<end; ++m){
        dp[m] = work.test(m);
        for(int s = m; s; s = (s-1)&m)
            if(dp[s]+dp[m^s]>dp[m]) dp[m] = dp[s]+dp[m^s];
    } cout << n-dp[(1<<n)-1] << '\n';
}