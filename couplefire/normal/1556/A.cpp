#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if((a+b)%2==1){
            cout << -1 << '\n';
            continue;
        }
        if(a==0 && b==0){
            cout << 0 << '\n';
        }
        else if(a==b){
            cout << 1 << '\n';
        } else cout << 2 << '\n';
    }
}