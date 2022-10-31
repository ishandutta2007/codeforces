#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n < 3) cout << -1 << endl;
        if(n == 3) cout << 1 << " " << 0 << " " << 0 << endl;
        if(n == 4) cout << -1 << endl;
        if(n == 5) cout << 0 << " " << 1 << " " << 0 << endl;
        if(n == 6) cout << 2 << " " << 0 << " " << 0 << endl;
        if(n == 7) cout << 0 << " " << 0 << " " << 1 << endl;
        if(n > 7){
            int cnt3 = 0;
            while(n%5 != 0) n-= 3, cnt3++;
            cout << cnt3 << " " << n/5 << " " << 0 << endl;
        }
    }
}