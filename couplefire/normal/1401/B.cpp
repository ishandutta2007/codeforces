#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int x1, y1, z1; cin >> x1 >> y1 >> z1;
        int x2, y2, z2; cin >> x2 >> y2 >> z2;
        int ans = 0;
        if(z1 <= y2){
            ans += 2*z1;
            if(x1 >= z2) cout << ans << endl;
            else cout << ans-2*(z2-x1) << endl;
        }
        else{
            ans += 2*y2;
            if(z2+y2 <= z1) cout << ans << endl;
            else if(x1 >= z2-(z1-y2)) cout << ans << endl;
            else cout << ans-2*(z2-(z1-y2)-x1) << endl;
        }
    }
}