#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        int cur = 1;
        for(int i = 1; i<100; i++){
            if(cur > n) break;
            int nxt = cur/__gcd(i, cur)*i;
            ans += i*(n/cur-n/nxt);
            ans %= MOD;
            cur = nxt;
        }
        cout << ans << endl;
    }
}