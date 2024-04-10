#include <bits/stdc++.h>
using namespace std;
#define INF 10000000000000ll

int n;
map<long long, long long> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    dp[INF] = 0;
    for(int i = 0; i<n; i++){
        long long a; cin >> a;
        auto it = dp.lower_bound(a);
        while(it != dp.end()){
            auto [x, y] = *it;
            dp[x%a] = max(dp[x%a], y+(x-x%a)*i);
            dp[a-1] = max(dp[a-1], y+(x-x%a-a)*i);
            dp.erase(it); it = dp.lower_bound(a);
        }
    }
    long long ans = 0;
    for(auto [x, y]: dp) ans = max(ans, x*n+y);
    cout << ans << endl;
}