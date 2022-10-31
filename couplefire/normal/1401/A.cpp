#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        if(n < k) cout << (k-n) << endl;
        else if((n+k)%2 == 1) cout << 1 << endl;
        else cout << 0 << endl;
    }
}