#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    if(n == 1) cout << 9 << endl;
    else{
        cout << 9 << 8;
        for(int i = 3; i<=n; i++) cout << (i+6)%10;
        cout << endl;
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) solve();
}