#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        long long a, b; cin >> a >> b;
        if(b == 1){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if(b == 2){
            cout << a << " " << 3*a << " " << 4*a << endl;
            continue;
        }
        cout << a*(b-1) << " " << a << " " << a*b << endl;
    }
}