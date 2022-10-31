#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

void solve(){
    int n; cin >> n;
    long long arr[n];
    for(int i = 0; i<n; i++) cin >> arr[i];
    int cnt[60]; fill(cnt, cnt+60, 0);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<60; j++) if(arr[i]&(1ll<<j)) cnt[j]++;
    }
    long long pw[60];
    pw[0] = 1;
    long long ans = 0;
    for(int i = 1; i<60; i++) pw[i] = pw[i-1]*2%MOD;
    for(int i = 0; i<n; i++){
        long long s1 = 0, s2 = 0;
        for(int a = 0; a<60; a++){
            if(arr[i]&(1ll<<a)){
                s1 += 1ll*cnt[a]*pw[a]%MOD;
            }
        }
        for(int a = 0; a<60; a++){
            if(arr[i]&(1ll<<a)){
                s2 += 1ll*n*pw[a]%MOD;
            }
            else s2 += 1ll*cnt[a]*pw[a]%MOD;
        }
        s1 %= MOD, s2 %= MOD;
        ans += s1*s2%MOD;
    }
    cout << ans%MOD << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }
}