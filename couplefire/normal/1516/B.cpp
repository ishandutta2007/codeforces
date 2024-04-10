#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> arr(n+1, 0);
    for(int i = 1; i<=n; i++) cin >> arr[i], arr[i] ^= arr[i-1];
    bool work = false;
    auto getxor = [&](int l, int r){
        return arr[r]^arr[l-1];
    };
    for(int i = 1; i<n; i++) work |= (getxor(1, i) == getxor(i+1, n));
    for(int i = 2; i<n; i++){
        for(int j = i; j<n; j++){
            work |= (getxor(1, i-1) == getxor(i, j) && getxor(i, j) == getxor(j+1, n));
        }
    }
    cout << (work?"YES":"NO") << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}