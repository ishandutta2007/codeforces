#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, k1, k2; cin >> n >> k1 >> k2;
        int w, b; cin >> w >> b;
        if(2*w <= (k1+k2) && 2*b <= (2*n-k1-k2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}