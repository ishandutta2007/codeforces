#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int a, b, c; cin >> a >> b >> c;
        if(a >= c){
            cout << -1 << " ";
        }
        else cout << 1 << " ";
        if(1ll*a*b <= 1ll*c) cout << -1 << endl;
        else cout << b << endl;
    }
}