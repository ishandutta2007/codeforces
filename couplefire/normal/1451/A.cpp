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
        if(n == 1){
            cout << 0 << endl;
            continue;
        }
        if(n == 2){
            cout << 1 << endl;
            continue;
        }
        if(n%2 == 0){
            cout << 2 << endl;
            continue;
        }
        if(n == 3){
            cout << 2 << endl;
            continue;
        }
        cout << 3 << endl;
    }
}