#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5010;
const ll oo = ll(1e18);
bitset<N> dp[N];
ll mn_tim[N], t[N], x[N], n;
 
void amin(ll &x, ll y) { x = min(x, y); }
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
 
    for (ll i = 1; i <= n; i++)
        cin >> t[i] >> x[i];
 
    x[0] = 0; t[0] = 0;
 
    fill(mn_tim, mn_tim + n + 1, oo);
 
    mn_tim[0] = 0;
 
    for (ll i = 0; i < n; i++){
        if (mn_tim[i] <= t[i]){
            ll nw = max(t[i], abs(x[i] - x[i + 1]) + mn_tim[i]);
 
            amin(mn_tim[i + 1], nw);
 
            for (ll j = i + 2; j <= n; j++){
                ll nw = max(t[i], abs(x[i] - x[j]) + mn_tim[i]);
 
                nw += abs(x[j] - x[i + 1]);
 
                if (nw <= t[i + 1])
                    dp[i + 1][j] = 1;
            }
        }
 
        for (ll j = i + 1; j <= n; j++) {
            if (!dp[i][j]) continue;
 
            if (i + 1 == j){
                if (i + 2 <= n){
                    ll nw = max(t[i + 1], t[i] + abs(x[i] - x[i + 2]));
 
                    amin(mn_tim[i + 2], nw);
                }
 
                for (ll z = i + 3; z <= n; z++){
                    ll nw = max(t[i + 1], abs(x[i] - x[z]) + t[i]);
 
                    nw += abs(x[z] - x[i + 2]);
 
                    if (nw <= t[i + 2])
                        dp[i + 2][z] = 1;
                }
            } else {
                ll nw = t[i] + abs(x[i] - x[i + 1]);
 
                if (nw <= t[i + 1])
                    dp[i + 1][j] = 1;
            }
        }
    }
 
    if (mn_tim[n] <= t[n] || dp[n - 1][n])
        cout << "YES";
    else cout << "NO";
 
    return 0;
}