#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, a, b; cin >> n >> a >> b;
        if(a == 1){
            cout << (n%b==1ll%b?"Yes":"No") << endl;
            continue;
        }
        int cur = 1;
        bool work = 0;
        while(cur <= n){
            if((n%b)==(cur%b)){
                work = 1;
                break;
            }
            cur *= a;
        }
        cout << (work?"Yes":"No") << endl;
    }
}