#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; long long k; cin >> n >> k;
    vector<long long> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    long long dif = abs(arr[1]-arr[0]);
    for(int i = 2; i<n; i++){
        dif = __gcd(dif, abs(arr[i]-arr[i-1]));
    }
    if((k%dif+dif)%dif != (arr[0]%dif+dif)%dif) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}