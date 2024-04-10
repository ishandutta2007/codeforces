#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, q;
long long inc = 1;
long long fac[21];

long long calc(int l, int r){return 1ll*(l+r+2)*(r-l+1)/2ll;}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    fac[0] = 1;
    for(int i = 1; i<=20; i++) fac[i] = fac[i-1]*i;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r; cin >> l >> r; --l; --r;
            if(n-r >= 20){
                cout << calc(l, r) << endl;
            }
            else{
                long long ans = calc(l, max(l-1, n-20));
                l = max(l, n-20+1);
                long long tmp = inc;
                vector<bool> used(20, false);
                vector<int> arr;
                for(int i = 1; i<=19; i++){
                    for(int j = 1; j<=19; j++){
                        if(used[j]) continue;
                        if(tmp <= fac[19-i]){
                            arr.push_back(j+n-19);
                            used[j] = 1;
                            break;
                        }
                        tmp -= fac[19-i];
                    }
                }
                // for(auto x : arr) cout << x << " ";
                // cout << endl;
                l -= n-19; r -= n-19;
                // cout << l << " " << r << endl;
                for(int i = l; i<=r; i++) ans += arr[i];
                cout << ans << endl;
            }
        }
        else{
            int x; cin >> x;
            inc += x;
        }
    }
}