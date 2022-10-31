#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    for(int i = 1; i<=k-(n-k)-1; i++) cout << i << " ";
    for(int i = k; i>=k-(n-k); i--) cout << i << " ";
    cout << endl;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}